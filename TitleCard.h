//
// Created by Jose Holguin on 6/5/24.
//

#ifndef GUI_TITLECARD_H
#define GUI_TITLECARD_H
#include "FontManager.h"
#include "Helper.h"
#include <iostream>

class TitleCard : public sf::RectangleShape{
private:
    sf::Text title;
public:
    TitleCard();
    TitleCard(float size, sf::Vector2f position, std::string title);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setTitle(std::string text);
    //void setSize(sf::Vector2f size);
    //void setPosition(sf::Vector2f position);
};


#endif //GUI_TITLECARD_H
