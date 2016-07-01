#include <pebble.h>
#include "config.h"

void init_setting_theme(WatchSettings *settings, WatchTheme *theme)
{
  switch((*theme))
  {
    case 0:
      settings->theme.fgColour = GColorDarkCandyAppleRed;
      settings->theme.bgColour = GColorWhite;
      break;

    case 1:
      settings->theme.fgColour = GColorWhite;
      settings->theme.bgColour= GColorDarkCandyAppleRed;
      break;

    case 2:
      settings->theme.fgColour = GColorDarkCandyAppleRed;
      settings->theme.bgColour = GColorBlack;
      break;

    case 3:
      settings->theme.fgColour = GColorWhite;
      settings->theme.bgColour = GColorBlack;
      break;

    case 4:
      settings->theme.fgColour = GColorBlack;
      settings->theme.bgColour = GColorWhite;
      break;
  }
}

void init_settings(WatchSettings *settings)
{
  bool isSayings = false;
  WatchTheme theme = PBL_IF_BW_ELSE(BlackWhite, RedWhite);

  if (persist_exists(MESSAGE_KEY_IS_SAYINGS))
  {
    isSayings = persist_read_bool(MESSAGE_KEY_IS_SAYINGS);
  }

  settings->isSayings = isSayings;

  if (persist_exists(MESSAGE_KEY_THEME))
  {
    theme = persist_read_int(MESSAGE_KEY_THEME);
  }

  init_setting_theme(settings, &theme);
}
