typedef enum
{
  RedWhite,
  WhiteRed,
  RedBlack,
  WhiteBlack,
  BlackWhite
} WatchTheme;

typedef struct
{
  GColor fgColour;
  GColor bgColour;
} ThemeColour;

typedef struct
{
  bool isSayings;
  ThemeColour theme;
} WatchSettings;

void init_setting_theme(WatchSettings *settings, WatchTheme *theme);
void init_settings(WatchSettings *settings);
