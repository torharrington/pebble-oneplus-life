#define MAX_SAYINGS 30

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
} Saying;

static const Saying sayings[MAX_SAYINGS] =
{
    {"NEVER", "SETTLE"},
    {"ONEPLUS", "COLETTE"},
    {"#HYPE", "#GTFO"},
    {"HYPE", "TRAIN"},
    {"LOOP VR", "ONEPLUS 3"},
    {"WEEKLY", "UPDATE"},
    {"GOT", "INVITES?"},
    {"OXYGEN", "OS"},
    {"ONEPLUS", "LIFE"},
    {"ONEPLUS", "ONE"},
    {"ONEPLUS", "TWO"},
    {"ONEPLUS", "THREE"},
    {"ONEPLUS", "3T"},
    {"ONEPLUS", "FIVE"},
    {"ONEPLUS", "5T"},
    {"ONEPLUS", "X"},
    {"ADAM", "KRISKO"},
    {"CARL", "PEI"},
    {"PETE", "LAU"},
    {"YOU GOT", "PEID!!!"},
    {"NO ONE", "NEEDS NFC"},
    {"ONEPLUS 2", "= 3"},
    {"SERVER", "ERROR"},
    {"OUT OF", "STOCK!!!"},
    {"HYDROGEN", "OS"},
    {"CYANOGEN", "MOD"},
    {"JELLY", "SCROLL"},
    {"SHOT ON", "ONEPLUS"},
    {"STAR", "WARS"},
    {"LAST", "JEDI"}
};
