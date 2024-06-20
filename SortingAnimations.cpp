//
// Created by Jose Holguin on 6/7/24.
//

#include "SortingAnimations.h"

SortingAnimations::SortingAnimations(sf::RenderWindow &window) {
    list.setNumberOfBars(800);
    list.setBarWidth(window);

    Button b(30, {(float)window.getSize().x/3, (float)window.getSize().y/2}, "Run Merge Animation");
    mergesort = b;

    Button c(30, {b.getPosition().x, b.getPosition().y + b.getSize().height*1.1f}, "Run Quicksort Animation");
    quicksort = c;
}

void SortingAnimations::draw(sf::RenderWindow &window) {
    window.draw(mergesort);
    window.draw(quicksort);
    if (mergesort.checkState(CLICKED)) {
        list.setBars();
        list.MergeSort(window);
        mergesort.disableState(CLICKED);
    }
    if (quicksort.checkState(CLICKED)) {
        list.setBars();
        list.QuickSort(window);
        quicksort.disableState(CLICKED);
    }
}

void SortingAnimations::eventHandler(sf::RenderWindow &window, sf::Event event) {
    mergesort.eventHandler(window, event);
    quicksort.eventHandler(window, event);
}

void SortingAnimations::update() {
    mergesort.update();
    quicksort.update();

}
