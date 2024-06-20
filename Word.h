//
// Created by Jose Holguin on 4/10/24.
//

#ifndef GUI_WORD_H
#define GUI_WORD_H
#include "FontManager.h"
#include "States.h"
#include "MouseEvents.h"
#include "EventHandler.h"

class Word : public sf::Text, public States, public EventHandler{
public:
    Word();
    Word(FontEnum font);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //GUI_WORD_H
