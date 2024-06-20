//
// Created by Jose Holguin on 4/17/24.
//

#include "KeyboardShortcuts.h"

bool KeyboardShortcuts::isUndo() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
}

