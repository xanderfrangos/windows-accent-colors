# windows-accent-colors

Node.js module for accessing the accent colors in Windows (via WinRT). This is intended as a supplement to [Electron's](https://electronjs.org/) own accent color detection. While Electron's accent color is the correct, user-selected color, it is not always the color used throughout Windows. This module provides Node.js/Electron developers with the derivative accent colors used throughout the Windows 10/11 UI. These colors are identical to the ones available via WinRT ([see Microsoft's documentation](https://docs.microsoft.com/en-us/uwp/api/Windows.UI.ViewManagement.UIColorType?view=winrt-22000)).

## Installation

```cmd
npm i windows-accent-colors
```

## Usage

Import the module and use `getAccentColors()`. For example:
```js
const AccentColors = require("windows-accent-colors");
const colors = AccentColors.getAccentColors();
console.log(`The color of sliders used in Windows 11 is: ${colors.accentLight2.hex}`);
```

The function `getAccentColors()` will return an object of all derivitaive accent colors in RGB and Hex format. For example:
```json
{
  "accent": { "r": 232, "g": 17, "b": 35, "hex": "#e81123" },
  "accentDark1": { "r": 210, "g": 14, "b": 30, "hex": "#d20e1e" },
  "accentDark2": { "r": 158, "g": 9, "b": 18, "hex": "#9e0912" },
  "accentDark3": { "r": 111, "g": 3, "b": 6, "hex": "#6f0306" },
  "accentLight1": { "r": 239, "g": 39, "b": 51, "hex": "#ef2733" },
  "accentLight2": { "r": 244, "g": 103, "b": 98, "hex": "#f46762" },
  "accentLight3": { "r": 251, "g": 157, "b": 139, "hex": "#fb9d8b" },
  "background": { "r": 0, "g": 0, "b": 0, "hex": "#000000" },
  "foreground": { "r": 255, "g": 255, "b": 255, "hex": "#ffffff" }
}
```