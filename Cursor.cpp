//
// Created by Jose Holguin on 4/28/24.
//

#include "Cursor.h"
#include <iostream>


Cursor::Cursor() {
    this->setFont(FontManager::getFont(ARIAL));
    this->setString("");
}

void Cursor::blink() {
    if (this->checkState(VISIBLE)) {
        sf::Time currentTime = clock.getElapsedTime();
        if (currentTime > sf::milliseconds(400)) {
            toggleString();
            clock.restart();
        }
    }
    else {
        this->setString("");
    }
}

void Cursor::toggleString() {
    if (this->getString() == "") {
        this->setString("|");
    }
    else {
        this->setString("");
    }
}

