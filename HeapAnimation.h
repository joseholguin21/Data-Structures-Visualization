//
// Created by Jose Holguin on 6/3/24.
//

#ifndef GUI_HEAPANIMATION_H
#define GUI_HEAPANIMATION_H
#include "Animations.h"
#include "Heap.h"

class HeapAnimation : public Animations{
private:
    TitleCard title;
    Heap heaptree;
    Button pop_button;
    Button clear_button;
    TextInput push_textbox;
    TextInput autogenerate_textbox;
    sf::FloatRect window_dimensions;
    void pop();
    void push(int data);
    void autogenerate(int size);
    void clear();
public:
    HeapAnimation(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    //virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
};


#endif //GUI_HEAPANIMATION_H
