//
// Created by Jose Holguin on 4/28/24.
//

#ifndef GUI_CURSOR_H
#define GUI_CURSOR_H
#include <SFML/Graphics.hpp>
#include "States.h"
#include "FontManager.h"

class Cursor : public sf::Text, public States{
private:
    sf::Clock clock;
public:
    Cursor();
    void blink();
    void toggleString();

};


#endif //GUI_CURSOR_H
