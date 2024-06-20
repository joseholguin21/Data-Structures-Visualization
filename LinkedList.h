//
// Created by Jose Holguin on 5/16/24.
//

#ifndef GUI_LINKEDLIST_H
#define GUI_LINKEDLIST_H

#include "Animations.h"

class LinkedList : public Animations{
private:
    std::vector<LinkedNode> nodelist;
    TitleCard title;
    Button pop_back_button;
    Button pop_front_button;
    TextInput push_back_textbox;
    TextInput remove_textbox;
    TextInput insert_after;
    TextInput push_front_textbox;
    sf::FloatRect window_dimensions;
    void movement();
    void push_back(std::string data);
    void remove(std::string data);
    void pop_back();
    void pop_front();
    void insert(std::string after, std::string data);
    void push_front(std::string b);
    void reposition();
public:
    LinkedList(sf::RenderWindow& window);
    void draw(sf::RenderWindow &window);
    //virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
};

#endif //GUI_LINKEDLIST_H
