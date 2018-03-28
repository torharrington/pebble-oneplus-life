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
        "messageKey": "IS_SAYINGS",
        "label": "Enable sayings",
        "defaultValue": false,
        "description": "Change the NEVER SETTLE text to a random saying; experience the fandom!"
      },
      {
        "type": "toggle",
        "messageKey": "IS_NOTCH",
        "label": "Enable notch",
        "defaultValue": false,
        "description": "Puts a notch on your Pebble screen! Match your OnePlus 6!"
      },
      {
        "type": "radiogroup",
        "messageKey": "THEME",
        "label": "Theme preset",
        "defaultValue": "0",
        "capabilities": [
          "COLOR"
        ],
        "options": [
          {
            "label": '<b style="color: #AA0000; background-color: #FFF; border-radius: 5px; display: block; width: 240px; height: 40px; font-weight: bold; line-height: 40px; font-size: 1.5em; text-align: center;">NEVER SETTLE</b>',
            "value": "0"
          },
          {
            "label": '<b style="color: #FFF; background-color: #AA0000; border-radius: 5px; display: block; width: 240px; height: 40px; font-weight: bold; line-height: 40px; font-size: 1.5em; text-align: center;">NEVER SETTLE</b>',
            "value": "1"
          },
          {
            "label": '<b style="color: #AA0000; background-color: #000; border-radius: 5px; display: block; width: 240px; height: 40px; font-weight: bold; line-height: 40px; font-size: 1.5em; text-align: center;">NEVER SETTLE</b>',
            "value": "2"
          },
          {
            "label": '<b style="color: #FFF; background-color: #000; border-radius: 5px; display: block; width: 240px; height: 40px; font-weight: bold; line-height: 40px; font-size: 1.5em; text-align: center;">NEVER SETTLE</b>',
            "value": "3"
          },
          {
            "label": '<b style="color: #000; background-color: #FFF; border-radius: 5px; display: block; width: 240px; height: 40px; font-weight: bold; line-height: 40px; font-size: 1.5em; text-align: center;">NEVER SETTLE</b>',
            "value": "4"
          },
          {
            "label": '<b style="color: #fff; background-color: #0055FF; border-radius: 5px; display: block; width: 240px; height: 40px; font-weight: bold; line-height: 40px; font-size: 1.5em; text-align: center;">NEVER SETTLE</b>',
            "value": "5"
          },
          {
            "label": '<b style="color: #555; background-color: #000; border-radius: 5px; display: block; width: 240px; height: 40px; font-weight: bold; line-height: 40px; font-size: 1.5em; text-align: center;">NEVER SETTLE</b>',
            "value": "6"
          }
        ]
      },
      {
        "type": "radiogroup",
        "messageKey": "THEME",
        "label": "Theme preset",
        "defaultValue": "4",
        "capabilities": [
          "BW"
        ],
        "options": [
          {
            "label": '<b style="color: #FFF; background-color: #000; border-radius: 5px; display: block; width: 240px; height: 40px; font-weight: bold; line-height: 40px; font-size: 1.5em; text-align: center;">NEVER SETTLE</b>',
            "value": "3"
          },
          {
            "label": '<b style="color: #000; background-color: #FFF; border-radius: 5px; display: block; width: 240px; height: 40px; font-weight: bold; line-height: 40px; font-size: 1.5em; text-align: center;">NEVER SETTLE</b>',
            "value": "4"
          }
        ]
      },
      {
        "type": "submit",
        "defaultValue": "💾 save"
      }
    ]
  }
]
