//
// Created by Jose Holguin on 4/3/24.
//

#include "Heap.h"

void Heap::reheapifyUp(int childIndex) {
    int parentIndex = getParent(childIndex);

    if (data[childIndex] > data[parentIndex]) {
        std::swap(data[childIndex], data[parentIndex]);
        return reheapifyUp(parentIndex);
    }
}


void Heap::reheapifyDown(int parentIndex) {
    if (parentIndex == -1)
        return;
    int largest_child_Index = getMaxChild(parentIndex);
    if (data[parentIndex] < data[largest_child_Index]) {
        std::swap(data[largest_child_Index], data[parentIndex]);
        return reheapifyDown(largest_child_Index);
    }
}

int Heap::getLeftChild(int parentIndex) {
    return 2*parentIndex + 1;
}


int Heap::getRightChild(int parentIndex) {
    return 2*parentIndex + 2;
}


int Heap::getMaxChild(int parentIndex) {

//    if (data[getLeftChild(parentIndex)] >= data[getRightChild(parentIndex)])
//        return getLeftChild(parentIndex);
//    else
//        return getRightChild(parentIndex);

    int rindex = getRightChild(parentIndex);
    int lindex = getLeftChild(parentIndex);

    if (rindex < data.size() && data[rindex] >= data[lindex])
        return getRightChild(parentIndex);
    else if (lindex < data.size() && data[lindex] >= data[rindex])
        return getLeftChild(parentIndex);
    else
        return -1;
}


int Heap::getParent(int childIndex) {
    return (childIndex - 1)/2;
}

void Heap::push(const int &item) {
    data.push_back(item);
    reheapifyUp(data.size()-1);
    createHeapTree();
}

void Heap::pop() {
    data[0] = data.back();
    data.pop_back();
    reheapifyDown(0);
    createHeapTree();

}

int &Heap::top() {
    return data.front();
}


int Heap::getSize() {
    return data.size();
}


bool Heap::empty() {
    return data.empty();
}


bool Heap::isLeaf(int parentIndex) {
    return (getLeftChild(parentIndex) >= data.size()) && (getRightChild(parentIndex) >= data.size());
}


bool Heap::hasOneChild(int parentIndex) {
    return !isLeaf(parentIndex) && !hasTwoChildren(parentIndex);
}


bool Heap::hasTwoChildren(int parentIndex) {
    return ((getLeftChild(parentIndex) < data.size() && getRightChild(parentIndex) < data.size()));;
}


void Heap::createHeapTree() {
    heaptree.clear();
//    if (data.size() == 1) {
//        CircleNode root(70, {500, 100}, std::to_string(data.front()), 80, sf::Color::Green);
//        heaptree.push_back(root);
//    }
//    else {
        float size = 80;
        float angle = 80;
        int n = 1;
        for (int i = 0; i < data.size(); i++) {
            if (i == (pow(2, n) - 1)) {
                //std::cout << (pow(2, n) - 1) << " ";
                n++;
                //angle messes up on row 4
                angle = angle - 25;
                size = size - 15;
            }
            CircleNode node(size, {500, 100}, std::to_string(data[i]), angle, {200, 200, 250});
            heaptree.push_back(node);
        }


        for (int j = 0; j < data.size(); j++) {
            if (getRightChild(j) < data.size()) {
                heaptree[j].enableState(HIDDENR);
                int rindex = getRightChild(j);
                heaptree[rindex].setPosition(heaptree[j].getRightEndPoint());
            }
            if (getLeftChild(j) < data.size()) {
                heaptree[j].enableState(HIDDENL);
                int lindex = getLeftChild(j);
                heaptree[lindex].setPosition(heaptree[j].getLeftEndPoint());
            }
        }

   // }

    //return htree;
}


void Heap::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < heaptree.size(); i++) {
        window.draw(heaptree[i]);
    }
}

void Heap::clear() {
    heaptree.clear();
    data.clear();
}



