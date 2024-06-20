//
// Created by Jose Holguin on 6/3/24.
//

#include "HeapAnimation.h"

void HeapAnimation::pop() {
    if (!heaptree.empty())
        heaptree.pop();
}

void HeapAnimation::push(int data) {
    heaptree.push(data);
}

HeapAnimation::HeapAnimation(sf::RenderWindow &window) {
    window_dimensions.width = (float)window.getSize().x;
    window_dimensions.height = (float)window.getSize().y;
    TitleCard t(30, {window_dimensions.width/2.5f, 0}, "Heap Tree");
    title = t;

    TextInput textbox1(sf::Color::Black, {100, 40}, {100, window_dimensions.height - window_dimensions.height/4}, "Push");
    push_textbox = textbox1;

    TextInput autogen(sf::Color::Black, {150, 40}, {textbox1.getPosition().x*7, textbox1.getPosition().y}, "Autogenerate Tree Size");
    autogenerate_textbox = autogen;

    Button button(30, {textbox1.getPosition().x, textbox1.getPosition().y + 50}, "Pop Button");
    pop_button = button;

    Button clear(30, {button.getPosition().x, button.getPosition().y + 50}, "Clear Tree");
    clear_button = clear;
}


//void HeapAnimation::draw(sf::RenderTarget &window, sf::RenderStates states) const {
//    window.draw(heaptree);
//    window.draw(push_textbox);
//    window.draw(pop_button);
//    window.draw(title);
//}

void HeapAnimation::draw(sf::RenderWindow &window) {
    window.draw(heaptree);
    window.draw(push_textbox);
    window.draw(pop_button);
    window.draw(title);
    window.draw(autogenerate_textbox);
    window.draw(clear_button);
}

void HeapAnimation::eventHandler(sf::RenderWindow &window, sf::Event event) {
    push_textbox.eventHandler(window, event);
    pop_button.eventHandler(window, event);
    autogenerate_textbox.eventHandler(window, event);
    clear_button.eventHandler(window, event);
}

void HeapAnimation::update() {
    push_textbox.update();
    pop_button.update();
    autogenerate_textbox.update();
    clear_button.update();

    if (push_textbox.checkState(ENTERED)){
        push(stoi(push_textbox.getInput()));
        push_textbox.disableState(ENTERED);
    }
    if (pop_button.checkState(CLICKED)) {
        pop();
        pop_button.disableState(CLICKED);
    }
    if (autogenerate_textbox.checkState(ENTERED)) {
        autogenerate(stoi(autogenerate_textbox.getInput()));
        autogenerate_textbox.disableState(ENTERED);
    }
    if (clear_button.checkState(CLICKED)) {
        heaptree.clear();
        clear_button.disableState(CLICKED);
    }
}

void HeapAnimation::autogenerate(int size) {
    srand(time(0));
    heaptree.clear();

    for (int i=0; i < size; i++) {
        push((rand() % 1000) + 1);
    }

}


