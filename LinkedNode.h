//
// Created by Jose Holguin on 5/16/24.
//

#ifndef GUI_LINKEDNODE_H
#define GUI_LINKEDNODE_H


#include "ArrowShape.h"
#include "NodePtr.h"
#include "FontManager.h"

class LinkedNode : public sf::RectangleShape
{
private:
    NodePtr right;
    NodePtr left;
    sf::Vector2f position;
    sf::Text data;
    sf::Text key;
public:
    LinkedNode();
    LinkedNode(sf::Vector2f size, sf::Vector2f position, std::string data, std::string key);
    LinkedNode(sf::Vector2f size, sf::Vector2f position, std::string data);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(const sf::Vector2f &position);
    sf::Vector2f getPosition();
    void setRotate(float angle);
    void setSize(const sf::Vector2f& size);
    void setTransform();
    void move(const sf::Vector2f &position);
    sf::FloatRect getBounds();
    void setData(std::string data);
    std::string getData();
    void setKey(std::string key);
    std::string getKey();
};

#endif //GUI_LINKEDNODE_H
