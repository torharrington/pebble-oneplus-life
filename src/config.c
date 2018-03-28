#include <pebble.h>
#include "config.h"

void init_setting_theme(WatchSettings *settings, WatchTheme *theme)
{
  settings->theme.style = (*theme);

  switch((*theme))
  {
    case RedWhite:
      settings->theme.fgColour = GColorDarkCandyAppleRed;
      settings->theme.bgColour = GColorWhite;
      break;

    case WhiteRed:
      settings->theme.fgColour = GColorWhite;
      settings->theme.bgColour = GColorDarkCandyAppleRed;
      break;

    case RedBlack:
      settings->theme.fgColour = GColorDarkCandyAppleRed;
      settings->theme.bgColour = GColorBlack;
      break;

    case WhiteBlack:
      settings->theme.fgColour = GColorWhite;
      settings->theme.bgColour = GColorBlack;
      break;

    case BlackWhite:
      settings->theme.fgColour = GColorBlack;
      settings->theme.bgColour = GColorWhite;
      break;

    case Colette:
      settings->theme.fgColour = GColorWhite;
      settings->theme.bgColour = GColorBlueMoon;
      break;

    case MidnightBlack:
      settings->theme.fgColour = GColorDarkGray;
      settings->theme.bgColour = GColorBlack;
      break;

    case LavaRed:
      settings->theme.fgColour = GColorBlack;
      settings->theme.bgColour = GColorDarkCandyAppleRed;
  }
}

void init_settings(WatchSettings *settings)
{
  bool isSayings = false;
  bool isNotch = false;
  WatchTheme theme = PBL_IF_BW_ELSE(BlackWhite, RedWhite);

  if (persist_exists(MESSAGE_KEY_IS_SAYINGS))
  {
    isSayings = persist_read_bool(MESSAGE_KEY_IS_SAYINGS);
  }

  if (persist_exists(MESSAGE_KEY_IS_NOTCH))
  {
    isNotch = persist_read_bool(MESSAGE_KEY_IS_NOTCH);
  }

  settings->isSayings = isSayings;
  settings->isNotch = isNotch;

  if (persist_exists(MESSAGE_KEY_THEME))
  {
    theme = persist_read_int(MESSAGE_KEY_THEME);
  }

  init_setting_theme(settings, &theme);
}
