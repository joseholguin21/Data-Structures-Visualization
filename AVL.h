//
// Created by Jose Holguin on 6/5/24.
//

#ifndef GUI_AVL_H
#define GUI_AVL_H
#include "BST.h"


class AVL : public BST{
private:
    void rotateLeft(Node*& n);
    void rotateRight(Node*& n);
    void balance(Node*& node);
    int getBalanceFactor(Node* node);
    void updateHeight(Node*& node);
    void validate(Node*& node);
    int max(int lh, int rh);
    void copy(Node* node);
public:
    void push(const int& data);
    void remove(const int& data);
};


#endif //GUI_AVL_H
