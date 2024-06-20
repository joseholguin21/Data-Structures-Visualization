//
// Created by Jose Holguin on 5/30/24.
//

#include "HashAnimation.h"

HashAnimation::HashAnimation(sf::RenderWindow& window) {
    window_dimensions.width = (float)window.getSize().x;
    window_dimensions.height = (float)window.getSize().y;
    TitleCard t(30, {window_dimensions.width/2.5f, 0}, "HashTable");
    title = t;

    TextInput textbox1(sf::Color::Red, {150, 40}, {200, window_dimensions.height - window_dimensions.height/4}, "Key");
    //textbox1.setLabel("Key");
    insertkey_textbox = textbox1;

    TextInput textbox2(sf::Color::Blue, {150, 40}, {200, textbox1.getPosition().y + 50}, "Data");
    //textbox2.setLabel("Data");
    insertdata_textbox = textbox2;

    TextInput textbox3(sf::Color::Black, {150, 40}, {200, textbox2.getPosition().y + 50}, "Remove");
    //textbox3.setLabel("remove");
    remove_textbox = textbox3;

    Button clear(30, {textbox3.getPosition().x, textbox3.getPosition().y + 50}, "Clear Hash Table");
    clear_button = clear;
}

void HashAnimation::remove(std::string key) {
    int k = stoi(key);
    table.remove(k);
}

void HashAnimation::insert(const std::pair<int, int>& record) {
    table.insert({record.first, record.second});
}


//void HashAnimation::draw(sf::RenderTarget &window, sf::RenderStates states) const {
//    window.draw(table);
//    window.draw(remove_textbox);
//    window.draw(insertkey_textbox);
//    window.draw(insertdata_textbox);
//    window.draw(title);
//}

void HashAnimation::draw(sf::RenderWindow &window) {
    window.draw(table);
    window.draw(remove_textbox);
    window.draw(insertkey_textbox);
    window.draw(insertdata_textbox);
    window.draw(title);
    window.draw(clear_button);
}

void HashAnimation::eventHandler(sf::RenderWindow &window, sf::Event event) {
    remove_textbox.eventHandler(window, event);
    insertkey_textbox.eventHandler(window, event);
    insertdata_textbox.eventHandler(window, event);
    clear_button.eventHandler(window, event);
}

void HashAnimation::update() {
    remove_textbox.update();
    insertkey_textbox.update();
    insertdata_textbox.update();
    clear_button.update();

    if (insertkey_textbox.checkState(ENTERED) && insertdata_textbox.checkState(ENTERED)){
        insert({stoi(insertkey_textbox.getInput()), stoi(insertdata_textbox.getInput())});
        insertkey_textbox.disableState(ENTERED);
        insertdata_textbox.disableState(ENTERED);
    }
    if (remove_textbox.checkState(ENTERED)) {
        remove(remove_textbox.getInput());
        remove_textbox.disableState(ENTERED);
    }
    if (clear_button.checkState(CLICKED)) {
        table.clear();
        clear_button.disableState(CLICKED);
    }


}
