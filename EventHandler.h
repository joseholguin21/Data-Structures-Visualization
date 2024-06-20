//
// Created by Jose Holguin on 4/11/24.
//

#ifndef GUI_EVENTHANDLER_H
#define GUI_EVENTHANDLER_H
#include <SFML/Graphics.hpp>

class EventHandler {
private:
public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //GUI_EVENTHANDLER_H
