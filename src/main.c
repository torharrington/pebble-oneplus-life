#include <pebble.h>

typedef struct
{
  char header[10];
  char body[4];
  char footer[10];
} FaceText;

typedef struct
{
  char header[10];
  char footer[10];
} OneplusQuote;

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

static GFont fontLatoBlack;
static GFont fontRokkitBold;

static FaceText ft;
static OneplusQuote qt;

static void watch_init_default(int quoteIndex)
{
  switch(quoteIndex)
  {
    case 0:
      strcpy(qt.header, "NEVER");
      strcpy(qt.footer, "SETTLE");
      break;

    case 1:
      strcpy(qt.header, "#HYPE");
      strcpy(qt.footer, "#GTFO");
      break;

    case 2:
      strcpy(qt.header, "HYPE");
      strcpy(qt.footer, "TRAIN");
      break;

    case 3:
      strcpy(qt.header, "LOOP VR");
      strcpy(qt.footer, "OnePlus 3");
      break;

    case 4:
      strcpy(qt.header, "WEEKLY");
      strcpy(qt.footer, "UPDATE");
      break;

    case 5:
      strcpy(qt.header, "GOT");
      strcpy(qt.footer, "INVITES?");
      break;

    case 6:
      strcpy(qt.header, "OXYGEN");
      strcpy(qt.footer, "OS");
      break;

    case 7:
      strcpy(qt.header, "OnePlus");
      strcpy(qt.footer, "Life!");
      break;

    case 8:
      strcpy(qt.header, "OnePlus");
      strcpy(qt.footer, "One");
      break;

    case 9:
      strcpy(qt.header, "OnePlus");
      strcpy(qt.footer, "Two");
      break;

    case 10:
      strcpy(qt.header, "OnePlus");
      strcpy(qt.footer, "Three");
      break;

    case 11:
      strcpy(qt.header, "OnePlus");
      strcpy(qt.footer, "X");
      break;

    case 12:
      strcpy(qt.header, "Adam");
      strcpy(qt.footer, "Krisko");
      break;

    case 13:
      strcpy(qt.header, "Carl");
      strcpy(qt.footer, "Pei");
      break;

    case 14:
      strcpy(qt.header, "Pete");
      strcpy(qt.footer, "Lau");
      break;

    case 15:
      strcpy(qt.header, "You Got");
      strcpy(qt.footer, "PEID!!!");
      break;

    case 16:
      strcpy(qt.header, "No One");
      strcpy(qt.footer, "Needs NFC!");
      break;

    case 17:
      strcpy(qt.header, "OnePlus 2");
      strcpy(qt.footer, "= Three");
      break;

    case 18:
      strcpy(qt.header, "SERVER");
      strcpy(qt.footer, "ERROR");
      break;

    case 19:
      strcpy(qt.header, "OUT OF");
      strcpy(qt.footer, "STOCK!!!");
      break;

    default:
      strcpy(qt.header, "NEVER");
      strcpy(qt.footer, "SETTLE");
      break;
  }

  strcpy(ft.header, qt.header);
  strcpy(ft.body, "1");
  strcpy(ft.footer, qt.footer);
}

static void watch_set_text()
{
  text_layer_set_text(textLayerHeader, ft.header);
  text_layer_set_text(textLayerLogo, ft.body);
  text_layer_set_text(textLayerFooter, ft.footer);
}

static void watch_set_time()
{
  time_t now = time(NULL);
  struct tm *theTime = localtime(&now);

  strcpy(ft.header, MONTHS[theTime->tm_mon]);
  snprintf(ft.body, sizeof(ft.body), "%i", theTime->tm_mday);
  strftime(ft.footer, sizeof(ft.footer), clock_is_24h_style() ? "%H:%M" : "%I:%M %p", theTime);

  watch_set_text();
}

static void app_timer_callback(void *data)
{
  watch_init_default(rand() % 20);
  watch_set_text();
}

static void accel_tap_handler(AccelAxisType axis, int32_t direction)
{
  watch_set_time();
  app_timer_register(5000, app_timer_callback, NULL);
}

static void logo_layer_update_proc(Layer *layer, GContext *ctx)
{
  graphics_context_set_fill_color(ctx, PBL_IF_BW_ELSE(GColorBlack, GColorDarkCandyAppleRed));

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
  window_set_background_color(window, GColorWhite);

  fontLatoBlack = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_LATO_BLACK_24));
  fontRokkitBold = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_ROKKITT_BOLD_64));

  /* HEADER */
  textLayerHeader = text_layer_create(GRect(0, PBL_IF_ROUND_ELSE(12,4), bounds.size.w, 29));
  text_layer_set_font(textLayerHeader, fontLatoBlack);
  text_layer_set_text_color(textLayerHeader, PBL_IF_BW_ELSE(GColorBlack, GColorDarkCandyAppleRed));
  text_layer_set_background_color(textLayerHeader, GColorWhite);
  text_layer_set_text_alignment(textLayerHeader, GTextAlignmentCenter);

  layer_add_child(window_get_root_layer(s_window), (Layer *)textLayerHeader);

  /* LOGO TEXT */
  textLayerLogo = text_layer_create(GRect(PBL_IF_ROUND_ELSE(63,45), PBL_IF_ROUND_ELSE(45,38), 55, 73));
  text_layer_set_font(textLayerLogo, fontRokkitBold);
  text_layer_set_text_color(textLayerLogo, PBL_IF_BW_ELSE(GColorBlack, GColorDarkCandyAppleRed));
  text_layer_set_background_color(textLayerLogo, GColorWhite);
  text_layer_set_text_alignment(textLayerLogo, GTextAlignmentCenter);

  layer_add_child(window_get_root_layer(s_window), (Layer *)textLayerLogo);

  /* LOGO */
  layerLogo = layer_create(GRect(PBL_IF_ROUND_ELSE(52,34), PBL_IF_ROUND_ELSE(42,34), 87, 87));

  layer_add_child(window_get_root_layer(s_window), layerLogo);
  layer_set_update_proc(layerLogo, logo_layer_update_proc);

  /* FOOTER */
  textLayerFooter = text_layer_create(GRect(0, 130, bounds.size.w, 29));
  text_layer_set_font(textLayerFooter, fontLatoBlack);
  text_layer_set_text_color(textLayerFooter, PBL_IF_BW_ELSE(GColorBlack, GColorDarkCandyAppleRed));
  text_layer_set_background_color(textLayerFooter, GColorWhite);
  text_layer_set_text_alignment(textLayerFooter, GTextAlignmentCenter);

  layer_add_child(window_get_root_layer(s_window), (Layer *)textLayerFooter);

  watch_init_default(0);
  watch_set_text();

  accel_tap_service_subscribe(accel_tap_handler);
}

static void prv_window_unload(Window *window) {
  text_layer_destroy(textLayerHeader);
  text_layer_destroy(textLayerLogo);

  layer_destroy(layerLogo);

  text_layer_destroy(textLayerFooter);

  accel_tap_service_unsubscribe();
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
