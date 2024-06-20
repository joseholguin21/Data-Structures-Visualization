//
// Created by Jose Holguin on 5/21/24.
//

#ifndef GUI_BINARYSEARCHTREE_H
#define GUI_BINARYSEARCHTREE_H
#include "Animations.h"

class BinarySearchTree : public Animations{
private:
    sf::Text order;
    TitleCard title;
    BST list;
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
    BinarySearchTree(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    //virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
};


#endif //GUI_BINARYSEARCHTREE_H
