//
// Created by Jose Holguin on 5/16/24.
//

#include "ArrowShape.h"
ArrowShape::ArrowShape() {
    ArrowShape({50, 50});
}

ArrowShape::ArrowShape(const sf::Vector2f &size) : head(size.x / 6, 3)
{
    body.setSize({ head.getGlobalBounds().height /3.0f,size.x*2 / 3.0f});
    body.setFillColor(sf::Color::Black);
    sf::FloatRect b = body.getGlobalBounds();
    sf::FloatRect h = head.getGlobalBounds();
    head.setOrigin({h.left + h.width/2, h.top});
    head.setFillColor(sf::Color::Black);
    body.setOrigin({b.left + b.width/2, b.top + b.height});
    body.setPosition({h.left, h.top + h.height + b.height});
    setPosition({h.left, h.top + h.height + b.height});
}

void ArrowShape::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(head);
    window.draw(body);
}

void ArrowShape::setPosition(const sf::Vector2f &position) {
    body.setPosition(position);
    setTransform();
    this->position = position;
}

sf::Vector2f ArrowShape::getPosition() {
    return body.getPosition();
}

void ArrowShape::setRotate(float angle) {
    body.rotate(angle);
    head.rotate(angle);
    setTransform();
}

void ArrowShape::setSize(const sf::Vector2f &size) {
    sf::CircleShape head;
    sf::RectangleShape body;
    head = sf::CircleShape(size.x/6, 3);
    body.setSize({ head.getGlobalBounds().height /3.0f,size.x*2 / 3.0f});
    sf::FloatRect b = body.getGlobalBounds();
    sf::FloatRect h = head.getGlobalBounds();
    head.setOrigin({h.left + h.width/2, h.top});
    body.setOrigin({b.left + b.width/2, b.top + b.height});
    body.setPosition({h.left, h.top + h.height + b.height});
    this->body = body;
    this->head = head;
    setPosition(position);
}

void ArrowShape::setTransform()
{
    sf::Transform t;
    t = body.getTransform();
    sf::FloatRect b = body.getLocalBounds();
    sf::FloatRect h = head.getLocalBounds();
    sf::Vector2f p = t.transformPoint(b.left + b.width/2, b.top - h.height);
    head.setPosition(p);
}

void ArrowShape::move(const sf::Vector2f &position) {
    body.move(position);
    setTransform();
    this->position = position;
}

sf::FloatRect ArrowShape::getGlobalBounds() const{
    sf::FloatRect arrowBounds;
    arrowBounds.height = size.y;
    arrowBounds.width = size.x;
    return arrowBounds;
}