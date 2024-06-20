//
// Created by Jose Holguin on 4/10/24.
//

#ifndef GUI_FONTMANAGER_H
#define GUI_FONTMANAGER_H
#include <map>
#include <SFML/Graphics.hpp>
#include "FontEnum.h"

class FontManager
{
private:
    static std::map<FontEnum, sf::Font> fonts;
    static void loadFont(FontEnum font);
    static std::string getFontPath(FontEnum);
public:
    static sf::Font& getFont(FontEnum);
};


#endif //GUI_FONTMANAGER_H
