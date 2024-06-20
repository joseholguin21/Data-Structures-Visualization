//
// Created by Jose Holguin on 5/9/24.
//

#include "Bars.h"

Bars::Bars() {

}

void Bars::setBars() {
    bar.clear();
    srand(time(nullptr));
    std::vector<float> h = getRandomHeights();

    for (int i=0; i < arraysize; i++) {
        sf::RectangleShape b;
        b.setFillColor(sf::Color::White);
        b.setSize({barwidth, -h[i]});
        b.setPosition({barwidth * i, 1000});
        bar.push_back(b);
    }
}

void Bars::setNumberOfBars(int numofbars) {
    arraysize = numofbars;
}

void Bars::setBarWidth(sf::RenderWindow &window) {
    barwidth = (float)window.getSize().x/arraysize;
}

std::vector<float> Bars::getRandomHeights() {
    int numofbars = arraysize;
    std::vector<float> h(arraysize);

    for (int i=0; i < numofbars; i++)
        {
            h[i]= ((rand() % numofbars)+1);
        }
    int z=0;
    while (z < numofbars)
        {
            for (int i = 0; i < numofbars; i++)
            {
                for (int j = i + 1; j < numofbars; j++)
                {
                    if (h[i] == h[j])
                    {
                        h[i]= ((rand() % numofbars)+1);
                    }
                }
            }
            z++;
        }
    return h;
}





//void Bars::draw(sf::RenderTarget &window, sf::RenderStates states) const {
//    for (int i=0; i < bar.size(); i++)
//        window.draw(bar[i]);
//
//    std::vector<sf::RectangleShape> copy;
//    for (int i=0; i < bar.size(); i++) {
//        copy.push_back(bar[i]);
//    }
//    merge_sort(window, &copy[0], arraysize);
//}




void Bars::merge_sort(sf::RenderWindow &window, sf::RectangleShape *bars, int size) {
    int n1;
    int n2;
    if (size > 1) {
        n1 = size/2;
        n2 = size - n1;
        merge_sort(window, bars, n1);
        merge_sort(window, bars + n1, n2);
        merge(window, bars, n1, n2);
    }
}

void Bars::merge(sf::RenderWindow &window, sf::RectangleShape *bars, int n1, int n2) {
    sf::RectangleShape* temp = new sf::RectangleShape[n1 + n2];

    int copied = 0, copied1 = 0, copied2 = 0;

    //sf::sleep(sf::seconds(0.01));
    while (copied1 < n1 && copied2 < n2) {
        sf::sleep(sf::seconds(0.001));
        if (bars[copied1].getGlobalBounds().height < (bars+n1)[copied2].getGlobalBounds().height)
            temp[copied] = bars[copied1++];
        else
            temp[copied] = (bars+n1)[copied2++];
        reposition();
        (bars + copied++)->setFillColor(sf::Color::Red);
        windowdraw(window);
    }

    while (copied1 < n1) {
        sf::sleep(sf::seconds(0.001));
        temp[copied] = bars[copied1++];
        reposition();
        (bars + copied++)->setFillColor(sf::Color::Red);
        windowdraw(window);
    }
    while (copied2 < n2) {
        sf::sleep(sf::seconds(0.001));
        temp[copied] = (bars+n1)[copied2++];
        reposition();
        (bars + copied++)->setFillColor(sf::Color::Red);
        windowdraw(window);
    }

    for (int i=0; i < n1+n2; i++) {
        sf::sleep(sf::seconds(0.001));
        temp[i].setFillColor(sf::Color::White);
        bars[i] = temp[i];
        reposition();
        windowdraw(window);
    }

    delete[] temp;
}

void Bars::reposition() {
    for (int i=0; i < arraysize; i++) {
        bar[i].setPosition({barwidth * (float)i, 1000});
        bar[i].setFillColor(sf::Color::White);
    }
}

void Bars::quick_sort(sf::RenderWindow &window, sf::RectangleShape *data, int size) {
    int pivot_index;
    int left_size;
    int right_size;

    if (size > 1) {
        partition(window, data, size, pivot_index);
        left_size = pivot_index;
        right_size = size - pivot_index - 1;
        quick_sort(window, data, left_size);
        quick_sort(window, data+pivot_index+1, right_size);
    }
}


void Bars::partition(sf::RenderWindow &window, sf::RectangleShape *data, int size, int& pivot_index) {
    float pivot = data[0].getGlobalBounds().height;
    int i = 1;
    int j = size-1;


    while (i <= j) {
        while (data[i].getGlobalBounds().height <= pivot && i < size) {
            i++;
        }
        while (data[j].getGlobalBounds().height > pivot) {
            j--;
        }
        if (i < j) {
            std::swap(data[i], data[j]);
            reposition();
            sf::sleep(sf::seconds(0.05));
            data[i].setFillColor(sf::Color::Red);
            data[j].setFillColor(sf::Color::Red);
            windowdraw(window);
        }
    }
    pivot_index = j;
    std::swap(data[pivot_index], data[0]);
    reposition();
    windowdraw(window);
}

void Bars::draw(sf::RenderTarget &window) {
    for (int i=0; i < bar.size(); i++) {
        window.draw(bar[i]);
    }

}

void Bars::windowdraw(sf::RenderWindow &window) {
    window.clear();
    (*this).draw(window);
    window.display();
}



void Bars::MergeSort(sf::RenderWindow &window) {
    merge_sort(window, &bar[0], arraysize);
}

void Bars::QuickSort(sf::RenderWindow &window) {
    quick_sort(window, &bar[0], arraysize);
}
