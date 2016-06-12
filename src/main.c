#include <pebble.h>

static Window *s_window;

static TextLayer *textLayerHeader;
static TextLayer *textLayerFooter;

static Layer *layerLogo;

static GFont fontLatoBlack;
static GFont fontRokkitBold;

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

static void app_timer_callback(void *data)
{
}

static void accel_tap_handler(AccelAxisType axis, int32_t direction)
{
}

static void logo_layer_update_proc(Layer *layer, GContext *ctx)
{
  graphics_context_set_fill_color(ctx, GColorWhite);

  /* Square */
  graphics_fill_rect(ctx, GRect(0, 11, 48, 8), 0, GCornerNone);
  graphics_fill_rect(ctx, GRect(0, 19, 8, 59), 0, GCornerNone);
  graphics_fill_rect(ctx, GRect(0, 78, 76, 8), 0, GCornerNone);
  graphics_fill_rect(ctx, GRect(68, 38, 8, 40), 0, GCornerNone);

  /* Plus */
  graphics_fill_rect(ctx, GRect(57, 11, 30, 8), 0, GCornerNone);
  graphics_fill_rect(ctx, GRect(68, 0, 8, 30), 0, GCornerNone);
}

static void prv_window_load(Window *window) {
  GRect bounds = layer_get_bounds(window_get_root_layer(window));
  window_set_background_color(window, GColorDarkCandyAppleRed);

  fontLatoBlack = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_LATO_BLACK_24));
  fontRokkitBold = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_ROKKITT_BOLD_64));

  /* LOGO */
  layerLogo = layer_create(GRect(34, 34, 87, 87));

  layer_add_child(window_get_root_layer(s_window), layerLogo);
  layer_set_update_proc(layerLogo, logo_layer_update_proc);

  /* HEADER */
  textLayerHeader = text_layer_create(GRect(0, 4, bounds.size.w, 29));
  text_layer_set_font(textLayerHeader, fontLatoBlack);
  text_layer_set_text_color(textLayerHeader, GColorWhite);
  text_layer_set_background_color(textLayerHeader, GColorDarkCandyAppleRed);
  text_layer_set_text_alignment(textLayerHeader, GTextAlignmentCenter);
  text_layer_set_text(textLayerHeader, "NEVER");

  layer_add_child(window_get_root_layer(s_window), (Layer *)textLayerHeader);

  /* LOGO TEXT */
  // textLayerLogo = text_layer_create(GRect(60, 47, 24, 73));
  // text_layer_set_font(textLayerLogo, fontRokkitBold);
  // text_layer_set_text_color(textLayerLogo, GColorWhite);
  // text_layer_set_background_color(textLayerLogo, GColorDarkCandyAppleRed);
  // text_layer_set_text_alignment(textLayerLogo, GTextAlignmentCenter);
  // text_layer_set_text(textLayerLogo, "1");
  //
  // layer_add_child(window_get_root_layer(s_window), (Layer *)textLayerLogo);

  /* FOOTER */
  textLayerFooter = text_layer_create(GRect(0, 130, bounds.size.w, 29));
  text_layer_set_font(textLayerFooter, fontLatoBlack);
  text_layer_set_text_color(textLayerFooter, GColorWhite);
  text_layer_set_background_color(textLayerFooter, GColorDarkCandyAppleRed);
  text_layer_set_text_alignment(textLayerFooter, GTextAlignmentCenter);
  text_layer_set_text(textLayerFooter, "SETTLE");

  layer_add_child(window_get_root_layer(s_window), (Layer *)textLayerFooter);

  accel_tap_service_subscribe(accel_tap_handler);
}

static void prv_window_unload(Window *window) {
  text_layer_destroy(textLayerFooter);
  text_layer_destroy(textLayerHeader);
  layer_destroy(layerLogo);
}

static void prv_init(void) {
  s_window = window_create();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .load = prv_window_load,
    .unload = prv_window_unload,
  });
  const bool animated = true;
  window_stack_push(s_window, animated);
}

static void prv_deinit(void) {
  window_destroy(s_window);
}

int main(void) {
  prv_init();
  app_event_loop();
  prv_deinit();
}
