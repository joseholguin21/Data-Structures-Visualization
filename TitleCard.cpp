//
// Created by Jose Holguin on 6/5/24.
//

#include "TitleCard.h"

TitleCard::TitleCard() : TitleCard(30, {0, 0}, "default"){

}

TitleCard::TitleCard(float size, sf::Vector2f position, std::string title) {
    this->title.setString(title);
    this->title.setFillColor(sf::Color::Red);
    this->title.setFont(FontManager::getFont(ALFASLABONE));
    this->title.setCharacterSize(size);
    this->title.setPosition(position);


    this->setFillColor(sf::Color::Green);
    this->setOutlineColor(sf::Color::Black);
    this->setOutlineThickness(5);
    this->setSize({this->title.getGlobalBounds().width * 1.3f, this->title.getGlobalBounds().height * 1.3f});
    this->setPosition(position);

    sf::RectangleShape t = *this;
    Helper::centerText(t, this->title);
    //std::cout << "(" << this->getPosition().x << " " << this->getPosition().y << ") ";
}

void TitleCard::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    sf::RectangleShape t = *this;
    window.draw(t);
    window.draw(title);
}

void TitleCard::setTitle(std::string text) {
    sf::Text t;
    t.setString(text);
    this->title = t;
}

//void TitleCard::setSize(sf::Vector2f size) {
//
//}

//void TitleCard::setPosition(sf::Vector2f position) {
//    sf::Transformable::setPosition(position);
//}
