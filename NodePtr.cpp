//
// Created by Jose Holguin on 5/16/24.
//

#include "NodePtr.h"

NodePtr::NodePtr() {

}

NodePtr::NodePtr(sf::Vector2f size, sf::Vector2f position, direction direction) {
    this->setSize({size.x/2.0f, size.y});
    this->setFillColor({100, 10, 120});
    this->setOrigin({this->getGlobalBounds().left + this->getGlobalBounds().width/2,
                     this->getGlobalBounds().top + this->getGlobalBounds().height/2});
    this->setPosition(position);
    this->arrow = ArrowShape(size);
    this->direct = direction;
    if (direction == RIGHT)
    {
        this->arrow.setRotate(90);
        this->arrow.setPosition({this->getPosition().x + this->getGlobalBounds().width/2,
                                 this->getPosition().y});
    }
    else if (direction == LEFT)
    {
        this->arrow.setRotate(270);
        this->arrow.setPosition({this->getPosition().x - this->getGlobalBounds().width/2,
                                 this->getPosition().y});
    }
}

void NodePtr::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    sf::RectangleShape r = *this;
    window.draw(r);
    window.draw(arrow);
}

void NodePtr::setPosition(const sf::Vector2f &position) {
    sf::Transformable::setPosition(position);
    setTransform();
    this->position = position;
}

sf::Vector2f NodePtr::getPosition() {
    return sf::Transformable::getPosition();
}

void NodePtr::setRotate(float angle) {
    this->rotate(angle);
    arrow.setRotate(angle);
    setTransform();
}

void NodePtr::setSize(const sf::Vector2f &size) {
    sf::RectangleShape body;
    body.setSize({size.x/3.0f, size.y});
    body.setOrigin({body.getGlobalBounds().left + body.getGlobalBounds().width/2,
                    body.getGlobalBounds().top + body.getGlobalBounds().height/2});
    body.setPosition(position);
    this->arrow = ArrowShape(size);
    if (direct == RIGHT)
    {
        body.setFillColor(sf::Color::Blue);
        arrow.setRotate(90);
        arrow.setPosition({body.getPosition().x + body.getGlobalBounds().width/2,
                           body.getPosition().y});
    }
    else if (direct == LEFT)
    {
        body.setFillColor(sf::Color::Red);
        arrow.setRotate(270);
        arrow.setPosition({body.getPosition().x - body.getGlobalBounds().width/2,
                           body.getPosition().y});
    }
    sf::RectangleShape::setSize(body.getSize());
    sf::RectangleShape::setOrigin(body.getOrigin());
    sf::RectangleShape::setPosition(position);
}

void NodePtr::setTransform() {
    sf::Vector2f p;
    sf::Transform t;
    t = this->getTransform();
    sf::FloatRect b = this->getLocalBounds();
    if (direct == RIGHT) {
        p = t.transformPoint(b.width, b.height / 2);
    }
    else
    {
        p = t.transformPoint(0, b.height / 2);
    }
    arrow.setPosition(p);
}

void NodePtr::move(const sf::Vector2f &position) {
    Transformable::move(position);
    setTransform();
    this->position = position;
}

sf::FloatRect NodePtr::getGlobalBounds() const{
    sf::FloatRect b;

    b.width = this->getLocalBounds().width + arrow.getGlobalBounds().width;
    b.height = this->getLocalBounds().height;
    return b;
}