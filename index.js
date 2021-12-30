"use strict";
const addon = require("bindings")("windows_accent_colors");
const { release } = require("os");

class AccentColors {
    constructor() {}
    getAccentColors = () => {
        try {
            if(process.platform !== 'win32' || parseInt(release().split('.')[2], 10) < 10240) {
                return {};
            }
            const colors = addon.getAccentColors();

            // Generate hex color
            for(const colorName in colors) {
                const color = colors[colorName]
                if(color.r !== undefined && color.g !== undefined && color.b !== undefined) {
                    const hex = {
                        r: color.r.toString(16),
                        g: color.g.toString(16),
                        b: color.b.toString(16)
                    }
                    hex.r = (hex.r.length === 1 ? '0' + hex.r : hex.r);
                    hex.g = (hex.g.length === 1 ? '0' + hex.g : hex.g);
                    hex.b = (hex.b.length === 1 ? '0' + hex.b : hex.b);
                    color.hex = `#${hex.r}${hex.g}${hex.b}`;
                }
            }

            return colors;
        } catch(e) {
            console.log("Couldn't get accent colors!", e);
            return {};
        }
    }
}

module.exports = new AccentColors();