//
// Created by Jose Holguin on 5/30/24.
//

#ifndef GUI_ANIMATIONS_H
#define GUI_ANIMATIONS_H
#include "LinkedNode.h"
#include "Button.h"
#include "TextInput.h"
#include "CircleNode.h"
#include "BST.h"
#include "AVL.h"
#include "TitleCard.h"
#include "EventHandler.h"

class Animations
        {
public:
    virtual void draw(sf::RenderWindow &window)= 0;
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) = 0;
    virtual void update() = 0;
};
#endif //GUI_ANIMATIONS_H
