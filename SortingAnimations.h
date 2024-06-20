//
// Created by Jose Holguin on 6/7/24.
//

#ifndef GUI_MERGESORTANIMATION_H
#define GUI_MERGESORTANIMATION_H
#include "Animations.h"
#include "Bars.h"

class SortingAnimations : public Animations{
private:
    Bars list;
    Button mergesort;
    Button quicksort;
public:
    SortingAnimations(sf::RenderWindow& window);
    //virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void draw(sf::RenderWindow& window);
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
};


#endif //GUI_MERGESORTANIMATION_H
