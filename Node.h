//
// Created by Jose Holguin on 3/25/24.
//

#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "CircleNode.h"
struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
    CircleNode circle;
    int height;
};

#endif //TREE_NODE_H
