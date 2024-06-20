//
// Created by Jose Holguin on 5/15/24.
//

#include "Button.h"

Button::Button() : Button(100, {0, 0}, "default"){

}

Button::Button(float size, sf::Vector2f position, std::string label) {

    this->label.setString(label);
    this->label.setFillColor(sf::Color::Black);
    this->label.setFont(FontManager::getFont(OPENSANS_BOLD));
    this->label.setCharacterSize(size);

    box.setFillColor({128, 128, 128});
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(5);
    box.setSize({this->label.getGlobalBounds().width*1.2f, this->label.getGlobalBounds().height*1.2f});
    box.setPosition(position);

    centerText();
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(label);
}

void Button::setLabel(std::string text) {
    this->label.setString(text);
    this->label.setCharacterSize(box.getGlobalBounds().height/1.3);
}

void Button::setSize(sf::Vector2f size) {
    box.setSize(size);
}

void Button::setPosition(sf::Vector2f position) {
    box.setPosition(position);
    this->label.setPosition(position);
}

sf::Vector2f Button::getPosition() {
    return box.getPosition();
}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents::mouseClicked(box.getGlobalBounds(), window, event)) {
        this->enableState(CLICKED);
    }
    else {
        this->disableState(CLICKED);
    }

    if (MouseEvents::isHovered(box.getGlobalBounds(), window)) {
        this->enableState(HOVERED);
    }
    else {
        this->disableState(HOVERED);
    }
}

void Button::update() {
    if(this->checkState(CLICKED)) {
        box.setFillColor(sf::Color::White);
    }
    else {
        box.setFillColor({128, 128, 128});
    }
    if (this->checkState(HOVERED)) {
        box.setFillColor({180, 140, 180});
    }
    else {
        box.setFillColor({128, 128, 128});
    }
}

Snapshot &Button::getSnapshot() {
    return currentSnapshot;
}

void Button::applySnapshot(const Snapshot &snapshot) {
    label.setString(snapshot.getText());
}

void Button::centerText()
{
    sf::FloatRect textRect = label.getGlobalBounds();
    sf::FloatRect tRect = box.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + label.getLocalBounds().left, center.y + label.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    label.setOrigin(rounded);
    label.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});
}

sf::FloatRect Button::getSize() {
    sf::FloatRect v;
    v.width = box.getGlobalBounds().width;
    v.height = box.getGlobalBounds().height;
    v.left = box.getPosition().x;
    v.top = box.getPosition().y;

    return v;
}
