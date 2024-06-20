//
// Created by Jose Holguin on 4/3/24.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
#include <vector>
#include <iostream>
#include "CircleNode.h"
#include <cmath>

class Heap : public sf::Drawable
{
private:
    std::vector<int> data;
    std::vector<CircleNode> heaptree;
    void reheapifyUp(int childIndex);
    void reheapifyDown(int parentIndex);
    int getLeftChild(int parentIndex);
    int getRightChild(int parentIndex);
    int getMaxChild(int parentIndex);
    int getParent(int childIndex);
public:
    void push(const int& item);
    void pop();
    void clear();
    int& top();
    int getSize();
    bool empty();
    void createHeapTree();
    bool isLeaf(int parentIndex);
    bool hasOneChild(int parentIndex);
    bool hasTwoChildren(int parentIndex);
    //void draw(sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif //HEAP_HEAP_H
