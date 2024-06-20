//
// Created by Jose Holguin on 5/9/24.
//

#ifndef MERGESORT_SFML_BARS_H
#define MERGESORT_SFML_BARS_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Bars{
private:
    std::vector<sf::RectangleShape> bar;
    int arraysize=0;
    float barwidth=0;
    std::vector<float> getRandomHeights();
    void windowdraw(sf::RenderWindow &window);
    void merge_sort(sf::RenderWindow &window, sf::RectangleShape *bar, int size);
    void merge(sf::RenderWindow &window, sf::RectangleShape *bars, int n1, int n2);
    void reposition();
    void quick_sort(sf::RenderWindow &window, sf::RectangleShape* bars, int size);
    void partition(sf::RenderWindow &window, sf::RectangleShape* data, int size, int& pivot_index);
public:
    Bars();
    void setBars();
    //void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void draw(sf::RenderTarget& window);
    void MergeSort(sf::RenderWindow &window);
    void QuickSort(sf::RenderWindow &window);
    void setNumberOfBars(int numofbars);
    void setBarWidth(sf::RenderWindow& window);
};


#endif //MERGESORT_SFML_BARS_H
