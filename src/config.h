typedef enum
{
  RedWhite,
  WhiteRed,
  RedBlack,
  WhiteBlack,
  BlackWhite,
  Colette,
  MidnightBlack,
  LavaRed
} WatchTheme;

typedef struct
{
  GColor fgColour;
  GColor bgColour;
  WatchTheme style;
} ThemeColour;

typedef struct
{
  bool isSayings;
  bool isNotch;
  ThemeColour theme;
} WatchSettings;

void init_setting_theme(WatchSettings *settings, WatchTheme *theme);
void init_settings(WatchSettings *settings);
