module.exports =
[
  {
    "type": "heading",
    "defaultValue": "OnePlus Life",
    "size": 1
  },
  {
    "type": "section",
    "items": [
      {
        "type": "toggle",
        "messageKey": "ENABLE_SAYINGS",
        "label": "Enable Sayings",
        "defaultValue": false,
        "description": "When this is enabled, the NEVER SETTLE text will change to a random saying; for the true community fandom experience!"
      },
      {
        "type": "radiogroup",
        "messageKey": "COLOUR_THEME",
        "label": "Theme",
        "defaultValue": "0",
        "capabilities": [
          "COLOR"
        ],
        "options": [
          {
            "label": '<b style="color: #AA0000; background-color: #FFF; display: block; width: 240px; height: 64px; font-weight: bold; line-height: 2em; font-size: 2em;text-align: center;">NEVER SETTLE</b>',
            "value": "0"
          },
          {
            "label": '<b style="color: #FFF; background-color: #AA0000; display: block; width: 240px; height: 64px; font-weight: bold; line-height: 2em; font-size: 2em;text-align: center;">NEVER SETTLE</b>',
            "value": "1"
          },
          {
            "label": '<b style="color: #AA0000; background-color: #000; display: block; width: 240px; height: 64px; font-weight: bold; line-height: 2em; font-size: 2em;text-align: center;">NEVER SETTLE</b>',
            "value": "2"
          },
          {
            "label": '<b style="color: #FFF; background-color: #000; display: block; width: 240px; height: 64px; font-weight: bold; line-height: 2em; font-size: 2em;text-align: center;">NEVER SETTLE</b>',
            "value": "3"
          },
          {
            "label": '<b style="color: #000; background-color: #FFF; display: block; width: 240px; height: 64px; font-weight: bold; line-height: 2em; font-size: 2em;text-align: center;">NEVER SETTLE</b>',
            "value": "4"
          }
        ]
      },
      {
        "type": "radiogroup",
        "messageKey": "COLOUR_THEME",
        "label": "Theme",
        "defaultValue": "4",
        "capabilities": [
          "BW"
        ],
        "options": [
          {
            "label": '<b style="color: #FFF; background-color: #000; display: block; width: 240px; height: 64px; font-weight: bold; line-height: 2em; font-size: 2em;text-align: center;">NEVER SETTLE</b>',
            "value": "3"
          },
          {
            "label": '<b style="color: #000; background-color: #FFF; display: block; width: 240px; height: 64px; font-weight: bold; line-height: 2em; font-size: 2em;text-align: center;">NEVER SETTLE</b>',
            "value": "4"
          }
        ]
      }
    ]
  },
  {
    "type": "submit",
    "defaultValue": "save"
  }
]
