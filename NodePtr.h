//
// Created by Jose Holguin on 5/16/24.
//

#ifndef GUI_NODEPTR_H
#define GUI_NODEPTR_H

#include "ArrowShape.h"


enum direction {LEFT, UP, RIGHT, DOWN};
class NodePtr : public sf::RectangleShape
{
private:
    ArrowShape arrow;
    direction direct;
    sf::Vector2f position;
public:
    NodePtr();
    NodePtr(sf::Vector2f size,  sf::Vector2f position, direction direction);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(const sf::Vector2f &position);
    sf::Vector2f getPosition();
    void setRotate(float angle);
    void setSize(const sf::Vector2f& size);
    void setTransform();
    void move(const sf::Vector2f &position);
    sf::FloatRect getGlobalBounds() const;
};


#endif //GUI_NODEPTR_H
