#include <pebble.h>

static Window *s_window;

static TextLayer *textLayerHeader;
static TextLayer *textLayerLogo;
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
  // text_layer_set_text(s_oneplus_text, "ONEPLUS");
  // text_layer_set_text(s_hour_text, "1");
  // text_layer_set_text(s_neversettle_text, "NEVER SETTLE");
}

static void accel_tap_handler(AccelAxisType axis, int32_t direction)
{
  // time_t now = time(NULL);
  // struct tm *theTime = localtime(&now);
  // static char timeBuffer[10];
  // static char dayBuffer[10];
  //
  // printf("%u\t%u", axis, (int)direction);
  //
  // clock_copy_time_string(timeBuffer, sizeof(timeBuffer));
  // text_layer_set_text(s_oneplus_text, timeBuffer);
  // text_layer_set_text(s_neversettle_text, MONTHS[theTime->tm_mon]);
  // snprintf(dayBuffer, sizeof(dayBuffer), "%i", theTime->tm_mday);
  // text_layer_set_text(s_hour_text, dayBuffer);
  //
  // printf("%i:%i:%i", theTime->tm_hour, theTime->tm_min, theTime->tm_sec);
  //
  // app_timer_register(5000, app_timer_callback, NULL);
}

static void minute_layer_update_proc(Layer *layer, GContext *ctx)
{
  graphics_context_set_fill_color(ctx, GColorWhite);
  graphics_fill_rect(ctx, GRect(0, 11, 30, 8), 0, GCornerNone);
  graphics_fill_rect(ctx, GRect(11, 0, 8, 30), 0, GCornerNone);
}

static void prv_window_load(Window *window) {
  GRect bounds = layer_get_bounds(window_get_root_layer(window));
  window_set_background_color(window, GColorDarkCandyAppleRed);

  fontLatoBlack = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_LATO_BLACK_24));
  fontRokkitBold = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_ROKKITT_BOLD_64));

  /* HEADER */
  textLayerHeader = text_layer_create(GRect(0, 4, bounds.size.w, 29));
  text_layer_set_font(textLayerHeader, fontLatoBlack);
  text_layer_set_text_color(textLayerHeader, GColorWhite);
  text_layer_set_background_color(textLayerHeader, GColorDarkCandyAppleRed);
  text_layer_set_text_alignment(textLayerHeader, GTextAlignmentCenter);
  text_layer_set_text(textLayerHeader, "NEVER");

  layer_add_child(window_get_root_layer(s_window), (Layer *)textLayerHeader);

  /* FOOTER */
  textLayerFooter = text_layer_create(GRect(0, 130, bounds.size.w, 29));
  text_layer_set_font(textLayerFooter, fontLatoBlack);
  text_layer_set_text_color(textLayerFooter, GColorWhite);
  text_layer_set_background_color(textLayerFooter, GColorDarkCandyAppleRed);
  text_layer_set_text_alignment(textLayerFooter, GTextAlignmentCenter);
  text_layer_set_text(textLayerFooter, "SETTLE");

  layer_add_child(window_get_root_layer(s_window), (Layer *)textLayerFooter);

  /* LOGO TEXT (body) */
  textLayerLogo = text_layer_create(GRect(40, 38, 66, 73));
  text_layer_set_font(textLayerLogo, fontRokkitBold);
  text_layer_set_text_color(textLayerLogo, GColorWhite);
  text_layer_set_background_color(textLayerLogo, GColorDarkCandyAppleRed);
  text_layer_set_text_alignment(textLayerLogo, GTextAlignmentCenter);
  text_layer_set_text(textLayerLogo, "1");

  layer_add_child(window_get_root_layer(s_window), (Layer *)textLayerLogo);

  accel_tap_service_subscribe(accel_tap_handler);
}

static void prv_window_unload(Window *window) {
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
