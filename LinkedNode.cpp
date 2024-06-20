//
// Created by Jose Holguin on 5/16/24.
//

#include "LinkedNode.h"

LinkedNode::LinkedNode() : LinkedNode({100, 50}, {100, 100}, "", ""){

}

//for hashttable
LinkedNode::LinkedNode(sf::Vector2f size, sf::Vector2f position, std::string data, std::string key) {
    this->setSize(size);
    this->setFillColor({126, 126, 126});
    this->setOrigin({this->getLocalBounds().left + this->getLocalBounds().width/2,
                     this->getLocalBounds().top + this->getLocalBounds().height/2});
    this->setPosition(position);

    //set the position of the nodeptrs
    this->right = NodePtr(size, position, RIGHT);
    right.setPosition({this->getPosition().x + this->getGlobalBounds().width/2 +
                       right.getLocalBounds().width/2, this->getPosition().y});

    this->left = NodePtr(size, position, LEFT);
    left.setPosition({this->getPosition().x - this->getGlobalBounds().width/2 -
                      right.getLocalBounds().width/2, this->getPosition().y});

    this->position= position;

    //data
    this->data.setString(data);
    this->data.setFont(FontManager::getFont(ARIAL));
    this->data.setCharacterSize(size.x/2.5);
    this->data.setOrigin({this->data.getLocalBounds().left + this->data.getLocalBounds().width/2,
                          this->data.getLocalBounds().top + this->data.getLocalBounds().height/2});
    this->key.setPosition(this->getPosition().x, this->getPosition().y - this->getGlobalBounds().height/3.5);
    this->data.setFillColor(sf::Color::Blue);

    //key
    this->key.setString(key);
    this->key.setFont(FontManager::getFont(ARIAL));
    this->key.setCharacterSize(size.x/2.5);
    this->key.setOrigin({this->key.getLocalBounds().left + this->key.getLocalBounds().width/2,
                          this->key.getLocalBounds().top + this->key.getLocalBounds().height/2});
    this->data.setPosition({this->key.getPosition().x, this->key.getPosition().y + this->key.getGlobalBounds().height*1.1f});
    this->key.setFillColor(sf::Color::Red);
}

//for normal linked list
LinkedNode::LinkedNode(sf::Vector2f size, sf::Vector2f position, std::string data) {
    this->setSize(size);
    this->setFillColor({136, 156, 196});
    this->setOrigin({this->getLocalBounds().left + this->getLocalBounds().width/2,
                     this->getLocalBounds().top + this->getLocalBounds().height/2});
    this->setPosition(position);

    //set the position of the nodeptrs
    this->right = NodePtr(size, position, RIGHT);
    right.setPosition({this->getPosition().x + this->getGlobalBounds().width/2 +
                       right.getLocalBounds().width/2, this->getPosition().y});

    this->left = NodePtr(size, position, LEFT);
    left.setPosition({this->getPosition().x - this->getGlobalBounds().width/2 -
                      right.getLocalBounds().width/2, this->getPosition().y});

    this->position= position;

    //data
    this->data.setString(data);
    this->data.setFont(FontManager::getFont(ARIAL));
    this->data.setCharacterSize(size.x/2.5);
    this->data.setOrigin({this->data.getLocalBounds().left + this->data.getLocalBounds().width/2,
                          this->data.getLocalBounds().top + this->data.getLocalBounds().height/2});
    this->data.setPosition(this->getPosition());
    this->data.setFillColor(sf::Color::Blue);

    //key
    this->key.setString("");
}


void LinkedNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    sf::RectangleShape r = *this;
    window.draw(r);
    window.draw(left);
    window.draw(right);
    window.draw(data);
    if (this->key.getString() != "K: ")
        window.draw(key);
}


void LinkedNode::setPosition(const sf::Vector2f &position) {
    Transformable::setPosition(position);
    this->data.setPosition(this->getPosition());
    setTransform();
}

sf::Vector2f LinkedNode::getPosition() {
    return sf::Transformable::getPosition();
}

void LinkedNode::setRotate(float angle) {
    this->rotate(angle);
    right.setRotate(angle);
    left.setRotate(angle);
    setTransform();
}

void LinkedNode::setSize(const sf::Vector2f &size) {
    RectangleShape::setSize(size);
}

void LinkedNode::setTransform() {
    sf::Vector2f rightpoint, leftpoint;
    sf::Transform t;
    t = this->getTransform();
    sf::FloatRect b = this->getLocalBounds();
    rightpoint = t.transformPoint(b.width + right.getLocalBounds().width/2, b.height / 2);
    right.setPosition(rightpoint);
    leftpoint = t.transformPoint(0 - right.getLocalBounds().width/2, b.height/2);
    left.setPosition(leftpoint);
}

void LinkedNode::move(const sf::Vector2f &position) {
    Transformable::move(position);
    this->data.setPosition(this->getPosition());
    setTransform();
    this->position = position;
}

sf::FloatRect LinkedNode::getBounds() {
    sf::FloatRect v;
    v.width = this->getLocalBounds().width + right.getGlobalBounds().height + left.getGlobalBounds().height;
    v.height = this->getLocalBounds().height;
    v.left = this->getPosition().x;
    v.top = this->getPosition().y;
    return v;
}

void LinkedNode::setData(std::string data) {
    this->data.setString(data);
}

std::string LinkedNode::getData() {
    return data.getString();
}

void LinkedNode::setKey(std::string key) {
    this->key.setString(key);
}

std::string LinkedNode::getKey() {
    return this->key.getString();
}
