//
// Created by Jose Holguin on 4/10/24.
//

#include "Word.h"

Word::Word() : Word(OPENSANS_BOLD){

}

Word::Word(FontEnum font) : sf::Text(){
    setFont(FontManager::getFont(font));
}

void Word::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents::isHovered(this->getGlobalBounds(), window)) {
        this->enableState(HOVERED);
        if (MouseEvents::mouseClicked(this->getGlobalBounds(), window, event)) {
            this->enableState(CLICKED);
        }
    }
    else {
        this->disableState(HOVERED);
    }
}

void Word::update() {
    if (this->checkState(HOVERED)){
        this->setFillColor(sf::Color::Blue);
    }
    else if(this->checkState(CLICKED)) {
        this->setFillColor(sf::Color::Yellow);
    }
    else {
        this->setFillColor(sf::Color::White);
    }
}
