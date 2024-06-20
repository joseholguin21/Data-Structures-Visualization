//
// Created by Jose Holguin on 5/30/24.
//

#ifndef GUI_APPLICATION_H
#define GUI_APPLICATION_H
#include "LinkedList.h"
#include "BinarySearchTree.h"
#include "HashAnimation.h"
#include "HeapAnimation.h"
#include "AVLAnimation.h"
#include "SortingAnimations.h"

class Application {
private:
    std::vector<Animations*> stuff;
    Button Next;
    Button Back;
    std::vector<Animations*>::iterator iter;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
public:
    void run();
};


#endif //GUI_APPLICATION_H
