//
// Created by Jose Holguin on 5/19/24.
//

#ifndef GUI_CIRCLENODE_H
#define GUI_CIRCLENODE_H
#include "States.h"
#include "FontManager.h"
#include <iostream>


class CircleNode : public States, public sf::CircleShape {
private:
    sf::RectangleShape leftbranch;
    sf::RectangleShape rightbranch;
    sf::Text data;
    sf::Vector2f leftend;
    sf::Vector2f rightend;
    float _angle;
    float _size;
    void setTransform();
public:
    CircleNode();
    CircleNode(float size, sf::Vector2f position, std::string data, float angle, sf::Color);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::Vector2f getLeftEndPoint();
    sf::Vector2f getRightEndPoint();
    void setPosition(sf::Vector2f position);
    void setSize(float size);
    void setData(std::string data);
    std::string getData();
    float getAngle();
    void setAngle(float angle);
    void move(const sf::Vector2f position);
};


#endif //GUI_CIRCLENODE_H
