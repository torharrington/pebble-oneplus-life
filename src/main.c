#include <pebble.h>
#include "config.h"
#include "sayings.h"

static const char *MONTHS[12] = {
  "JANUARY",
  "FEBRUARY",
  "MARCH",
  "APRIL",
  "MAY",
  "JUNE",
  "JULY",
  "AUGUST",
  "SEPTEMBER",
  "OCTOBER",
  "NOVEMBER",
  "DECEMBER"
};

static Window *s_window;

static TextLayer *textLayerHeader;
static TextLayer *textLayerFooter;
static TextLayer *textLayerLogo;
static Layer *layerLogo;
static BitmapLayer *bitmapLayerNotch;
static GBitmap *bitmapNotch;

static GFont fontLatoBlack;
static GFont fontRokkitBold;

static FaceText ft;
static WatchSettings settings;

static void watch_set_text()
{
  text_layer_set_text(textLayerHeader, ft.header);
  text_layer_set_text(textLayerLogo, ft.body);
  text_layer_set_text(textLayerFooter, ft.footer);
}

static void watch_set_saying(int index)
{
  if (index >= 0 && index < MAX_SAYINGS)
  {
    strcpy(ft.header, sayings[index].header);
    strcpy(ft.body, "1");
    strcpy(ft.footer, sayings[index].footer);
  }
}

static void watch_set_time()
{
  time_t now = time(NULL);
  struct tm *theTime = localtime(&now);

  strcpy(ft.header, MONTHS[theTime->tm_mon]);
  snprintf(ft.body, sizeof(ft.body), "%i", theTime->tm_mday);
  strftime(ft.footer, sizeof(ft.footer), clock_is_24h_style() ? "%H:%M" : "%I:%M %p", theTime);
}

static void app_timer_callback(void *data)
{
  int index = rand() % MAX_SAYINGS;

  if (settings.theme.style == Colette) {
    watch_set_saying(settings.isSayings ? index : 1);
  } else {
    watch_set_saying(settings.isSayings ? index : 0);
  }

  watch_set_text();
}

static void accel_tap_handler(AccelAxisType axis, int32_t direction)
{
  if (axis == ACCEL_AXIS_Y)
  {
    watch_set_time();
    watch_set_text();

    app_timer_register(5000, app_timer_callback, NULL);
  }
}

static void logo_layer_update_proc(Layer *layer, GContext *ctx)
{
  graphics_context_set_fill_color(ctx, settings.theme.fgColour);

  /* Square */
  graphics_fill_rect(ctx, GRect(0, 11, 48, 8), 0, GCornerNone);
  graphics_fill_rect(ctx, GRect(0, 19, 8, 59), 0, GCornerNone);
  graphics_fill_rect(ctx, GRect(0, 78, 76, 8), 0, GCornerNone);
  graphics_fill_rect(ctx, GRect(68, 38, 8, 40), 0, GCornerNone);

  /* Plus */
  graphics_fill_rect(ctx, GRect(57, 11, 30, 8), 0, GCornerNone);
  graphics_fill_rect(ctx, GRect(68, 0, 8, 30), 0, GCornerNone);
}

static void watch_refresh_theme()
{
  window_set_background_color(s_window, settings.theme.bgColour);

  text_layer_set_text_color(textLayerHeader, settings.theme.fgColour);
  text_layer_set_background_color(textLayerHeader, settings.theme.bgColour);

  text_layer_set_text_color(textLayerLogo, settings.theme.fgColour);
  text_layer_set_background_color(textLayerLogo, settings.theme.bgColour);

  text_layer_set_text_color(textLayerFooter, settings.theme.fgColour);
  text_layer_set_background_color(textLayerFooter, settings.theme.bgColour);

  layer_mark_dirty(layerLogo);
}

static void inbox_received_handler(DictionaryIterator *iter, void *context)
{
  Tuple *theme = dict_find(iter, MESSAGE_KEY_THEME);
  Tuple *isSayings = dict_find(iter, MESSAGE_KEY_IS_SAYINGS);
  Tuple *isNotch = dict_find(iter, MESSAGE_KEY_IS_NOTCH);

  if (theme)
  {
    WatchTheme _theme = (WatchTheme) (theme->value->int32 - 48);
    persist_write_int(MESSAGE_KEY_THEME, _theme);
    init_setting_theme(&settings, &_theme);
    watch_refresh_theme();
  }

  if (isSayings)
  {
    bool _isSayings = (bool) isSayings->value->int32;
    settings.isSayings = _isSayings;

    persist_write_bool(MESSAGE_KEY_IS_SAYINGS, _isSayings);

    watch_set_saying((settings.theme.style == Colette) ? 1 : 0);

    watch_set_text();
  }

  if (isNotch)
  {
    bool _isNotch = (bool) isNotch->value->int32;
    settings.isNotch = _isNotch;

    persist_write_bool(MESSAGE_KEY_IS_NOTCH, _isNotch);

    layer_set_hidden(bitmap_layer_get_layer(bitmapLayerNotch), !_isNotch);
  }
}

static void prv_window_load(Window *window) {
  GRect bounds = layer_get_bounds(window_get_root_layer(window));
  window_set_background_color(window, settings.theme.bgColour);

  fontLatoBlack = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_LATO_BLACK_24));
  fontRokkitBold = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_ROKKITT_BOLD_64));

  /* HEADER */
  textLayerHeader = text_layer_create(GRect(0, PBL_IF_ROUND_ELSE(12,4), bounds.size.w, 29));
  text_layer_set_font(textLayerHeader, fontLatoBlack);
  text_layer_set_text_alignment(textLayerHeader, GTextAlignmentCenter);

  layer_add_child(window_get_root_layer(s_window), (Layer *)textLayerHeader);

  /* LOGO TEXT */
  textLayerLogo = text_layer_create(GRect(PBL_IF_ROUND_ELSE(58,40), PBL_IF_ROUND_ELSE(45,38), 65, 73));
  text_layer_set_font(textLayerLogo, fontRokkitBold);
  text_layer_set_text_alignment(textLayerLogo, GTextAlignmentCenter);

  layer_add_child(window_get_root_layer(s_window), (Layer *)textLayerLogo);

  /* LOGO */
  layerLogo = layer_create(GRect(PBL_IF_ROUND_ELSE(52,34), PBL_IF_ROUND_ELSE(42,34), 87, 87));

  layer_add_child(window_get_root_layer(s_window), layerLogo);
  layer_set_update_proc(layerLogo, logo_layer_update_proc);

  /* FOOTER */
  textLayerFooter = text_layer_create(GRect(0, 130, bounds.size.w, 29));
  text_layer_set_font(textLayerFooter, fontLatoBlack);
  text_layer_set_text_alignment(textLayerFooter, GTextAlignmentCenter);

  layer_add_child(window_get_root_layer(s_window), (Layer *)textLayerFooter);

  /* NOTCH */
  #if defined(PBL_RECT)
    bitmapNotch = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_NOTCH);
    bitmapLayerNotch = bitmap_layer_create(GRect(42, 0, 60, 13));
    bitmap_layer_set_bitmap(bitmapLayerNotch, bitmapNotch);
    bitmap_layer_set_compositing_mode(bitmapLayerNotch, GCompOpSet);

    layer_add_child(window_get_root_layer(s_window), bitmap_layer_get_layer(bitmapLayerNotch));
    layer_set_hidden(bitmap_layer_get_layer(bitmapLayerNotch), !settings.isNotch);
  #endif

  watch_refresh_theme();
  watch_set_saying(0);
  watch_set_text();

  accel_tap_service_subscribe(accel_tap_handler);
}

static void prv_window_unload(Window *window) {
  accel_tap_service_unsubscribe();

  #if defined(PBL_RECT)
    bitmap_layer_destroy(bitmapLayerNotch);
    gbitmap_destroy(bitmapNotch);
  #endif

  text_layer_destroy(textLayerFooter);
  layer_destroy(layerLogo);

  text_layer_destroy(textLayerLogo);
  text_layer_destroy(textLayerHeader);

  fonts_unload_custom_font(fontRokkitBold);
  fonts_unload_custom_font(fontLatoBlack);
}

static void prv_init(void) {
  s_window = window_create();

  init_settings(&settings);

  window_set_window_handlers(s_window, (WindowHandlers) {
    .load = prv_window_load,
    .unload = prv_window_unload,
  });

  const bool animated = true;

  window_stack_push(s_window, animated);

  app_message_register_inbox_received(inbox_received_handler);
  app_message_open(128, 128);
}

static void prv_deinit(void) {
  app_message_deregister_callbacks();
  window_destroy(s_window);
}

int main(void) {
  prv_init();
  app_event_loop();
  prv_deinit();
}
