//
// Created by Jose Holguin on 4/10/24.
//

#include "FontManager.h"
std::map<FontEnum, sf::Font> FontManager::fonts;

void FontManager::loadFont(FontEnum font) {
    if (!fonts[font].loadFromFile(getFontPath(font)))
        exit(28);
}

std::string FontManager::getFontPath(FontEnum font) {
    switch(font) {
        case OPENSANS_BOLD:
            return "fonts/OpenSans-Bold.ttf";
        case ARIAL:
            return "fonts/arial.ttf";
        case SEYMOURONE:
            return "fonts/SeymourOne-Regular.ttf";
        case ALFASLABONE:
            return "fonts/AlfaSlabOne-Regular.ttf";
    }

}

sf::Font &FontManager::getFont(FontEnum font) {
    if (!fonts.count(font))
        loadFont(font);
    return fonts[font];
}
