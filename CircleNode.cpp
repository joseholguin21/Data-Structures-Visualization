//
// Created by Jose Holguin on 5/19/24.
//

#include "CircleNode.h"


CircleNode::CircleNode() : CircleNode(60, {100, 100}, "", 40, sf::Color::Cyan){

}


CircleNode::CircleNode(float size, sf::Vector2f position, std::string data, float angle, sf::Color color) {

    //int d = stoi(data);
    //std::cout << d << " ";
    _angle = angle;
    _size = size;

    this->setRadius(size/2);
    this->setOrigin({this->getLocalBounds().left + this->getLocalBounds().width/2,
                     this->getLocalBounds().top + this->getLocalBounds().height/2});
    this->setFillColor(color);
    this->setPosition(position);
    this->setOutlineColor(sf::Color::Blue);
    this->setOutlineThickness(size/10);

    //left branch
    leftbranch.setSize({size/3, size*3});
    leftbranch.setFillColor(sf::Color::Black);
    leftbranch.setOrigin({leftbranch.getLocalBounds().left + leftbranch.getLocalBounds().width/2,
                          leftbranch.getLocalBounds().top});
    leftbranch.setPosition(position);
    leftbranch.rotate(angle);

    //right branch
    rightbranch.setSize({size/3, size*3});
    rightbranch.setFillColor(sf::Color::Black);
    rightbranch.setOrigin({rightbranch.getLocalBounds().left + rightbranch.getLocalBounds().width/2,
                           rightbranch.getLocalBounds().top});
    rightbranch.setPosition(position);
    rightbranch.rotate(-angle);

    //disable states
    this->disableState(HIDDENR);
    this->disableState(HIDDENL);

    //create data and set position
    this->data.setString(data);
    this->data.setFont(FontManager::getFont(ARIAL));
    this->data.setFillColor(sf::Color::Magenta);
    this->data.setCharacterSize(size/2);
    this->data.setOrigin({this->data.getLocalBounds().left + this->data.getLocalBounds().width/2,
                          this->data.getLocalBounds().top + this->data.getLocalBounds().height/2});
    this->data.setPosition(position);


    //sets transformation points for branches
    setTransform();
}

void CircleNode::setPosition(sf::Vector2f position) {
    sf::Transformable::setPosition(position);
    this->data.setPosition(this->getPosition());
    rightbranch.setPosition(position);
    leftbranch.setPosition(position);
    setTransform();
}

void CircleNode::setTransform() {
    sf::Transform lefttransform = leftbranch.getTransform();
    sf::FloatRect l = leftbranch.getLocalBounds();
    leftend = lefttransform.transformPoint({l.getPosition().x + l.getSize().x/2,
                                            l.getPosition().y  + l.getSize().y});

    sf::Transform transform = rightbranch.getTransform();
    sf::FloatRect r = rightbranch.getLocalBounds();
    rightend = transform.transformPoint({-r.getPosition().x + r.getSize().x/2,
                                         r.getPosition().y  + r.getSize().y});
}

void CircleNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    sf::CircleShape cnode = *this;
    if (checkState(HIDDENL))
        window.draw(leftbranch);
    if (checkState(HIDDENR))
        window.draw(rightbranch);
    window.draw(cnode);
    window.draw(data);
}

sf::Vector2f CircleNode::getLeftEndPoint() {
    return leftend;
}

sf::Vector2f CircleNode::getRightEndPoint() {
    return rightend;
}

std::string CircleNode::getData() {
    std::string text = this->data.getString();
    return text;
}

void CircleNode::setData(std::string data) {
    this->data.setString(data);
}

void CircleNode::setSize(float size) {
    CircleNode c(size, this->getPosition(), data.getString(), _angle, sf::Color::Cyan);
    *this = c;
}

void CircleNode::setAngle(float angle) {
    CircleNode c(_size, this->getPosition(), data.getString(), angle, sf::Color::Cyan);
    *this = c;
//    leftbranch.setRotation(angle);
//    rightbranch.setRotation(-angle);
    //_angle = angle;
}

float CircleNode::getAngle() {
    return _angle;
}

void CircleNode::move(const sf::Vector2f position) {
    sf::Transformable::move(position);
    this->data.move(position);
    rightbranch.move(position);
    leftbranch.move(position);
    setTransform();
}
