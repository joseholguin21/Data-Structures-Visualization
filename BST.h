//
// Created by Jose Holguin on 3/25/24.
//

#ifndef TREE_BST_H
#define TREE_BST_H
#include "Node.h"
#include <queue>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "OrderTraversalEnum.h"

//second version
class BST : public sf::Drawable
{
private:
    sf::Vector2f window_dimensions;
    int _size= 0;
    std::string numberorder;
    ///remove functions
    Node*& findSuccessor(Node*& node);
    void swap(Node*& node1, Node*& node2);
//    void inorder(Node* node);
//    void preorder(Node* node);
//    void postorder(Node* node);
    void remove(Node*& node, Node*& prev, const int& data);
    void postorder(void (BST::*f)(Node*& data), Node*& node);
    void deleteNode(Node*& node);
    //int max(int lh, int rh);

    ///for returning traversal strings
    std::string breadth_first();
    void inorder(Node* node, std::string& order);
    void preorder(Node* node, std::string& order);
    void postorder(Node* node, std::string& order);

    void push(Node *&node, Node*& prev, const int &data);
    Node *search(Node*& prev, Node*& current, const int& data);

protected:
    ///note to self, only need to make root protected and the rest can be called BST::function
    Node *root = nullptr;
    sf::Vector2f position;
    bool isLeaf(Node* node);
    bool hasOneChild(Node* node);
    Node *& returnOneChild(Node* node);
    bool hasTwoChild(Node* node);
public:
    ///big three
    BST();
    BST(const BST& rightlist); ///copy constructor
    BST& operator= (const BST& rightlist); ///operator =
    ~BST(); ///destructor
    bool empty(); ///returns true if tree is empty, else false
    int size(); ///number of items in the tree
    void clear(); //clear tree
    void breadth_first(sf::RenderTarget &window);
    void push(const int& data);
    void remove(const int& data);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    std::string getOrder(OrderTraversal taversal);
    void move(const sf::Vector2f &position);
    void setDimensions(sf::Vector2f size);
};

//#include "BST.cpp"
#endif //TREE_BST_H
