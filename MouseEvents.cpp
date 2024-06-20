//
// Created by Jose Holguin on 4/11/24.
//

#include "MouseEvents.h"
int MouseEvents::clicks;
sf::Clock MouseEvents::clock;

sf::Time previousClick = sf::Time::Zero;

bool MouseEvents::isHovered(const sf::FloatRect &bounds, sf::RenderWindow &window) {
    return bounds.contains((sf::Vector2f)sf::Mouse::getPosition(window));
}

bool MouseEvents::mouseClicked(const sf::FloatRect &bounds, sf::RenderWindow &window, sf::Event event) {
    return event.type == sf::Event::MouseButtonPressed
    && bounds.contains((sf::Vector2f)sf::Mouse::getPosition(window));
}


void MouseEvents::clickTracker(const sf::FloatRect &bounds, sf::RenderWindow &window, sf::Event event) {
    sf::Time interval = sf::milliseconds(300);

    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Time currentTime = clock.getElapsedTime();
        if (currentTime - previousClick < interval)
        {
            clicks++;
        }

        previousClick = currentTime;
    }
}

bool MouseEvents::mouseDoubleClicked() {
    if (clicks == 1) {
        clicks = 0;
        return true;
    }
    else
        return false;
}

bool MouseEvents::mouseTripleClicked() {

}

bool MouseEvents::draggedOver(const sf::FloatRect &bounds, sf::RenderWindow &window, sf::Event event) {

}

