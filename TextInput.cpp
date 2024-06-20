//
// Created by Jose Holguin on 4/11/24.
//

#include "TextInput.h"
int DELETE_KEY = 8;
int ENTER_KEY = 10;

TextInput::TextInput() : TextInput(sf::Color::White, {50, 100}, {0, 0}, "Default") {

}

TextInput::TextInput(const sf::Color color, const sf::Vector2f &size, const sf::Vector2f &position, std::string label){


    box.setFillColor(color);
    box.setSize(size);
    box.setPosition(position);

    boxtext.setString("");
    boxtext.setFillColor(sf::Color::Black);
    boxtext.setFont(FontManager::getFont(ARIAL));
    boxtext.setPosition(position);
    boxtext.setCharacterSize(size.y/1.3);

    boxlabel.setString(label);
    boxlabel.setFillColor(color);
    boxlabel.setCharacterSize(size.y/1.3);
    boxlabel.setFont(FontManager::getFont(ARIAL));
    boxlabel.setPosition({(box.getPosition().x - boxlabel.getGlobalBounds().width)/1.05f, box.getPosition().y});

    cursor.setPosition(position);
    cursor.setFillColor(sf::Color::Black);
    cursor.setCharacterSize(size.y/1.3);
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(boxlabel);
    window.draw(boxtext);
    window.draw(cursor);
}

void TextInput::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (this->checkState(CLICKED) && event.type == sf::Event::TextEntered) {
        if (event.text.unicode >=0 && event.text.unicode < 128) {
            input(event.text.unicode);
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        disableState(CLICKED);
    }
    if (MouseEvents::isHovered(box.getGlobalBounds(), window)) {
        this->enableState(HOVERED);
        if (MouseEvents::mouseClicked(box.getGlobalBounds(), window, event)) {
            this->toggleState(CLICKED);
        }
//        MouseEvents::clickTracker(box.getGlobalBounds(), window, event);
//        if (MouseEvents::mouseDoubleClicked()) {
//            this->toggleState(DOUBLECLICK);
//        }
    }
    else {
        this->disableState(HOVERED);
    }
}

void TextInput::input(unsigned int asciiValue) {
    std::string stringtext = boxtext.getString();
    //if key is enter
    if (asciiValue == ENTER_KEY) {
        this->disableState(CLICKED);
        this->enableState(ENTERED);
    } else if (asciiValue == DELETE_KEY) {
        if (!stringtext.empty())
            stringtext.pop_back();
    } else if (stringtext.length() <= textLimit) {
        stringtext += (char) asciiValue;
        //saving text;
    }
    HistoryNode node;
    node.component = this;
    node.snap = currentSnapshot;

    History::pushHistory(node);
    boxtext.setString(stringtext);
    currentSnapshot.setText(stringtext);
//    std::string text = boxtext.getString();
//    std::cout << text << " ";
}


void TextInput::update() {
    if (this->checkState(HOVERED)){
        box.setFillColor(sf::Color::Cyan);
    }
    else {
        box.setFillColor({250, 211, 211});
    }

    if(this->checkState(CLICKED)) {
        box.setFillColor(sf::Color::White);
        cursor.enableState(VISIBLE);
        cursor.setPosition({box.getGlobalBounds().left + boxtext.getGlobalBounds().width, box.getGlobalBounds().top});
    }
    else {
        cursor.disableState(VISIBLE);
    }

//    if(this->checkState(DOUBLECLICK)) {
//        box.setFillColor(sf::Color::Red);
//    }

    cursor.blink();
    currentSnapshot.setStates(getStatesMap());
}


void TextInput::setLabel(const std::string &label) {
    boxlabel.setString(label);
    boxlabel.setPosition({box.getPosition().x - boxlabel.getGlobalBounds().width - box.getGlobalBounds().width/8
                          , box.getPosition().y});
}

void TextInput::setLabelSize(const unsigned int &size) {
    boxlabel.setCharacterSize(size);
    boxlabel.setPosition({box.getPosition().x - boxlabel.getGlobalBounds().width - box.getGlobalBounds().width/8
                                 , box.getPosition().y});
}

void TextInput::setPosition(const sf::Vector2f &position) {
    boxtext.setPosition(position);
    box.setPosition(position);
}

Snapshot &TextInput::getSnapshot() {
    return currentSnapshot;
}

void TextInput::applySnapshot(const Snapshot &snapshot) {
    std::map<StateEnum, bool> prevStates = snapshot.getStates();
    std::string prevtext = snapshot.getText();

    boxtext.setString(prevtext);
    this->setStatesMap(prevStates);

    if (prevtext.empty()) {
        currentSnapshot.setText("");
        this->disableState(CLICKED);
    }
}


std::string TextInput::getInput() {
    return boxtext.getString();
}

sf::Vector2f TextInput::getPosition() {
    return box.getPosition();
}
