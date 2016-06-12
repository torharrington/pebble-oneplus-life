#include <pebble.h>

static Window *s_window;

static TextLayer *s_oneplus_text;
static TextLayer *s_neversettle_text;
static TextLayer *s_hour_text;

static BitmapLayer *s_sigal_bitmap_layer;
static GBitmap *s_sigal_bitmap;
static Layer *s_minute_layer;

static GFont s_lato_regular;
static GFont s_lato_bold;
static GFont s_rokkit_bold;

static const char *MONTHS[12] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

static void app_timer_callback(void *data)
{
  text_layer_set_text(s_oneplus_text, "ONEPLUS");
  text_layer_set_text(s_hour_text, "1");
  text_layer_set_text(s_neversettle_text, "NEVER SETTLE");
}

static void accel_tap_handler(AccelAxisType axis, int32_t direction)
{
  time_t now = time(NULL);
  struct tm *theTime = localtime(&now);
  static char timeBuffer[10];
  static char dayBuffer[10];

  printf("%u\t%u", axis, (int)direction);

  clock_copy_time_string(timeBuffer, sizeof(timeBuffer));
  text_layer_set_text(s_oneplus_text, timeBuffer);
  text_layer_set_text(s_neversettle_text, MONTHS[theTime->tm_mon]);
  snprintf(dayBuffer, sizeof(dayBuffer), "%i", theTime->tm_mday);
  text_layer_set_text(s_hour_text, dayBuffer);

  printf("%i:%i:%i", theTime->tm_hour, theTime->tm_min, theTime->tm_sec);

  app_timer_register(5000, app_timer_callback, NULL);
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

  s_lato_bold = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_LATO_BOLD_18));
  s_lato_regular = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_LATO_REGULAR_18));
  s_rokkit_bold = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_ROKKITT_BOLD_64));

  /* ONEPLUS */
  s_oneplus_text = text_layer_create(GRect(31, 0, 82, 22));
  text_layer_set_font(s_oneplus_text, s_lato_regular);
  text_layer_set_text_color(s_oneplus_text, GColorWhite);
  text_layer_set_background_color(s_oneplus_text, GColorDarkCandyAppleRed);
  text_layer_set_text_alignment(s_oneplus_text, GTextAlignmentCenter);
text_layer_set_text(s_oneplus_text, "ONEPLUS");

  layer_add_child(window_get_root_layer(s_window), (Layer *)s_oneplus_text);

  /* NEVER SETTLE */
  s_neversettle_text = text_layer_create(GRect(10, 138, 124, 22));
  text_layer_set_font(s_neversettle_text, s_lato_bold);
  text_layer_set_text_color(s_neversettle_text, GColorWhite);
  text_layer_set_background_color(s_neversettle_text, GColorDarkCandyAppleRed);
  text_layer_set_text_alignment(s_neversettle_text, GTextAlignmentCenter);
  text_layer_set_text(s_neversettle_text, "NEVER SETTLE");

  layer_add_child(window_get_root_layer(s_window), (Layer *)s_neversettle_text);

  /* HOUR */
  s_hour_text = text_layer_create(GRect(40, 38, 66, 73));
  text_layer_set_font(s_hour_text, s_rokkit_bold);
  text_layer_set_text_color(s_hour_text, GColorWhite);
  text_layer_set_background_color(s_hour_text, GColorDarkCandyAppleRed);
  text_layer_set_text_alignment(s_hour_text, GTextAlignmentCenter);
  text_layer_set_text(s_hour_text, "1");

  layer_add_child(window_get_root_layer(s_window), (Layer *)s_hour_text);

  /* SIGAL */
  s_sigal_bitmap_layer = bitmap_layer_create(GRect(35, 45, 75, 75));
  s_sigal_bitmap = gbitmap_create_with_resource(RESOURCE_ID_SIGAL_BITMAP);
  bitmap_layer_set_compositing_mode(s_sigal_bitmap_layer, GCompOpSet);
  bitmap_layer_set_bitmap(s_sigal_bitmap_layer, s_sigal_bitmap);

  layer_add_child(window_get_root_layer(s_window), (Layer *)s_sigal_bitmap_layer);

  s_minute_layer = layer_create(GRect(91, 34, 30, 30));
  layer_add_child(window_get_root_layer(s_window), s_minute_layer);

  layer_set_update_proc(s_minute_layer, minute_layer_update_proc);
  layer_mark_dirty(s_minute_layer);

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
