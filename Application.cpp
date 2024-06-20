//
// Created by Jose Holguin on 5/30/24.
//

#include "Application.h"

void Application::eventHandler(sf::RenderWindow &window, sf::Event event) {
    Next.eventHandler(window, event);
    Back.eventHandler(window, event);
    if (Next.checkState(CLICKED)) {
        iter++;
        Next.disableState(CLICKED);
        if (iter == stuff.end()) {
            iter = stuff.begin();
        }
    }
    else if (Back.checkState(CLICKED)) {
        if (iter == stuff.begin()) {
            iter = stuff.end()-1;
        }
        else {
            iter--;
        }
        Back.disableState(CLICKED);
    }
}

void Application::update() {
    Next.update();
    Back.update();
}

void Application::run() {
    sf::RenderWindow window({1000, 1000, 32}, "Data Structures");
    Button button1(30, {0, 0}, "Back");
    Back = button1;
    Button button2(30, {(float)window.getSize().x - 80, 0}, "Next");
    Next = button2;

    LinkedList list(window);
    stuff.push_back(&list);
    BinarySearchTree tree(window);
    stuff.push_back(&tree);
    AVLAnimation avl(window);
    stuff.push_back(&avl);
    HeapAnimation heap(window);
    stuff.push_back(&heap);
    HashAnimation hash(window);
    stuff.push_back(&hash);
    SortingAnimations merge(window);
    stuff.push_back(&merge);

    iter = stuff.begin();
    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }

            (*iter)->eventHandler(window, event);
            eventHandler(window, event);
        }

        (*iter)->update();
        update();
        window.clear({211, 211, 211});
        (*iter)->draw(window);
        window.draw(Back);
        window.draw(Next);
        window.display();
    }
}
