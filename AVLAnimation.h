//
// Created by Jose Holguin on 6/5/24.
//

#ifndef GUI_AVLANIMATION_H
#define GUI_AVLANIMATION_H
#include "Animations.h"

class AVLAnimation : public Animations{
private:
    sf::Text order;
    TitleCard title;
    AVL list;
    TextInput push_textbox;
    TextInput remove_textbox;
    TextInput autogenerate_textbox;
    Button breadth_order;
    Button inorder;
    Button preorder;
    Button postorder;
    Button clear;
    sf::Vector2f window_dimensions;
    void push(std::string data);
    void remove(std::string data);
    void breadth_first();
    void in_order();
    void pre_order();
    void post_order();
    void movement();
    void autogenerate(int size);
public:
    AVLAnimation(sf::RenderWindow &window);
    //virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void draw(sf::RenderWindow &window);
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
};


#endif //GUI_AVLANIMATION_H
