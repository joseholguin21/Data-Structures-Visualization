//
// Created by Jose Holguin on 5/16/24.
//

#ifndef GUI_ARROWSHAPE_H
#define GUI_ARROWSHAPE_H
#include <iostream>
#include <SFML/Graphics.hpp>

class ArrowShape : public sf::Drawable
{
private:
    sf::RectangleShape body;
    sf::CircleShape head;
    sf::Vector2f size;
    sf::Vector2f position;
public:
    ArrowShape();
    ArrowShape(const sf::Vector2f& size);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(const sf::Vector2f &position);
    sf::Vector2f getPosition();
    void setRotate(float angle);
    void setSize(const sf::Vector2f& size);
    void setTransform();
    void move(const sf::Vector2f &position);
    sf::FloatRect getGlobalBounds() const;

};


#endif //GUI_ARROWSHAPE_H
