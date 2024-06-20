//
// Created by Jose Holguin on 5/16/24.
//

#include "LinkedList.h"

LinkedList::LinkedList(sf::RenderWindow& window) {
    window_dimensions.width = (float)window.getSize().x;
    window_dimensions.height = (float)window.getSize().y;
    TitleCard t(30, {window_dimensions.width/2.5f, 0}, "Linked List");
    title = t;

    TextInput textbox1(sf::Color::Black, {150, 40}, {200, window_dimensions.height - window_dimensions.height/3}, "Push Back");
    push_back_textbox = textbox1;

    TextInput textbox2(sf::Color::Black, {150, 40}, {200, textbox1.getPosition().y + 50}, "Remove");
    remove_textbox = textbox2;

    TextInput textbox3(sf::Color::Black, {150, 40}, {200, textbox2.getPosition().y + 50}, "Insert After");
    insert_after = textbox3;

    TextInput textbox4(sf::Color::Black, {150, 40}, {200, textbox3.getPosition().y + 50}, "Push Front");
    push_front_textbox = textbox4;

    Button button1(30, {200, textbox4.getPosition().y + 50}, "Pop Back");
    pop_back_button = button1;

    Button button2(30, {200, button1.getPosition().y + 50}, "Pop Front");
    pop_front_button = button2;
}

//void LinkedList::reposition() {
//    std::vector<LinkedNode> copy = nodelist;
//    nodelist.clear();
//
//    for (int i=0; i < copy.size(); i++) {
//        push_back(copy[i].getData());
//    }
//}

void LinkedList::reposition() {
    for (int i=1; i < nodelist.size(); i++) {
        sf::FloatRect prevnodesize = nodelist[i-1].getBounds();
        nodelist[i].setPosition({prevnodesize.left + prevnodesize.width, prevnodesize.top});
    }
}


void LinkedList::push_back(std::string data) {

    if (nodelist.empty()) {
        LinkedNode node({80, 80}, {110, window_dimensions.height/3}, data);
        nodelist.push_back(node);
    }
    else {
        sf::FloatRect prevnodesize = nodelist[nodelist.size()-1].getBounds();
        LinkedNode node({80, 80}, {nodelist[nodelist.size() - 1].getPosition().x + prevnodesize.width, nodelist[nodelist.size() - 1].getPosition().y}, data);
        nodelist.push_back(node);
    }
}

void LinkedList::remove(std::string data) {

    if (data == nodelist.back().getData()) {
        pop_back();
    }
    else {
        for (int i = 0; i < nodelist.size(); i++) {
            if (nodelist[i].getData() == data) {
                nodelist.erase(nodelist.begin() + i);
                break;
            }
        }

        reposition();
    }

}

void LinkedList::pop_back() {
    nodelist.pop_back();
}

void LinkedList::pop_front() {
    if (!nodelist.empty()) {
        nodelist.erase(nodelist.begin());
        reposition();
    }
}

void LinkedList::insert(std::string after, std::string data) {

    if (nodelist.end()->getData() == after) {
        push_back(data);
    }
    else {
        for (int i = 0; i < nodelist.size(); i++) {
            if (nodelist[i].getData() == after) {
                sf::FloatRect prevnodesize = nodelist[i - 1].getBounds();
                LinkedNode node({80, 80},
                                {nodelist[i - 1].getPosition().x + prevnodesize.width, nodelist[i - 1].getPosition().y},
                                data);
                nodelist.insert(nodelist.begin() + i + 1, node);
                break;
            }
        }
    }
    reposition();
}


void LinkedList::push_front(std::string b) {
    LinkedNode node({80, 80}, {nodelist.begin()->getPosition()}, b);
    nodelist.insert(nodelist.begin(), node);
    reposition();
}

void LinkedList::eventHandler(sf::RenderWindow &window, sf::Event event) {
    pop_back_button.eventHandler(window, event);
    push_back_textbox.eventHandler(window, event);
    remove_textbox.eventHandler(window, event);
    insert_after.eventHandler(window, event);
    push_front_textbox.eventHandler(window, event);
    pop_front_button.eventHandler(window, event);

    movement();
}

void LinkedList::update() {
    pop_back_button.update();
    push_back_textbox.update();
    remove_textbox.update();
    insert_after.update();
    push_front_textbox.update();
    pop_front_button.update();

    if (pop_back_button.checkState(CLICKED) && !nodelist.empty()) {
        pop_back();
        pop_back_button.disableState(CLICKED);
    }
    if (insert_after.checkState(ENTERED) && push_back_textbox.checkState(ENTERED)) {
        insert(insert_after.getInput(), push_back_textbox.getInput());
        insert_after.disableState(ENTERED);
        push_back_textbox.disableState(ENTERED);
    }
    if (push_back_textbox.checkState(ENTERED)) {
        push_back(push_back_textbox.getInput());
        push_back_textbox.disableState(ENTERED);
    }
    if (remove_textbox.checkState(ENTERED) && !nodelist.empty()) {
        remove(remove_textbox.getInput());
        remove_textbox.disableState(ENTERED);
    }
    if (push_front_textbox.checkState(ENTERED)) {
        push_front(push_front_textbox.getInput());
        push_front_textbox.disableState(ENTERED);
    }
    if (pop_front_button.checkState(CLICKED)) {
        pop_front();
        pop_front_button.disableState(CLICKED);
    }
}

void LinkedList::movement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        nodelist.begin()->move({20, 0});
        reposition();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        nodelist.begin()->move({-20, 0});
        reposition();
    }
}


//void LinkedList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
//    if (!nodelist.empty()) {
//        for (auto &i: nodelist) {
//            window.draw(i);
//        }
//    }
//    window.draw(pop_back_button);
//    window.draw(push_back_textbox);
//    window.draw(remove_textbox);
//    window.draw(insert_after);
//    window.draw(push_front_textbox);
//    window.draw(title);
//}

void LinkedList::draw(sf::RenderWindow &window) {
    if (!nodelist.empty()) {
        for (auto &i: nodelist) {
            window.draw(i);
        }
    }
    window.draw(pop_back_button);
    window.draw(pop_front_button);
    window.draw(push_back_textbox);
    window.draw(remove_textbox);
    window.draw(insert_after);
    window.draw(push_front_textbox);
    window.draw(title);
}
