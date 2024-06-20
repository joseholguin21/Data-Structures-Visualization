//
// Created by Jose Holguin on 4/11/24.
//

#ifndef GUI_MOUSEEVENTS_H
#define GUI_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>
#include <iostream>

class MouseEvents {
public:
    static bool isHovered(const sf::FloatRect& bounds, sf::RenderWindow& window);
    // returns true if the mouse clicks anywhere in the window
    static bool mouseClicked(const sf::FloatRect &bounds, sf::RenderWindow& window, sf::Event event);
    // returns true if the mouse has been double clicked
    static bool mouseDoubleClicked();
    //returns true if the mouse has been triple clicked
    static bool mouseTripleClicked();
    // returns if the object has been clicked and the mouse has dragged over the object
    static bool draggedOver(const sf::FloatRect& bounds, sf::RenderWindow& window, sf::Event event);
    // returns tru if the mouse is hovered over the object
    static void clickTracker(const sf::FloatRect &bounds, sf::RenderWindow &window, sf::Event event);
private:
    // this is what I used to determine if a double click or triple click occurred
    // you don't have to use this if you don't want to
    static int clicks;
    static sf::Clock clock;
};


#endif //GUI_MOUSEEVENTS_H
