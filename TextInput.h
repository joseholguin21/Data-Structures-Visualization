//
// Created by Jose Holguin on 4/11/24.
//

#ifndef GUI_TEXTINPUT_H
#define GUI_TEXTINPUT_H
#include "GuiComponent.h"
#include "FontManager.h"
#include "History.h"
#include "Cursor.h"

#define textLimit 10

class TextInput : public GuiComponent{
private:
    Snapshot currentSnapshot;
    sf::RectangleShape box;
    sf::Text boxlabel, boxtext;
    Cursor cursor;
    void input(unsigned int asciiValue);
public:
    TextInput();
    TextInput(const sf::Color color, const sf::Vector2f &size, const sf::Vector2f &position, std::string label);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

// from EventHandler
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

//from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

//for setting box text and position
    void setLabel(const std::string &label);
    void setLabelSize(const unsigned int &size);
    void setPosition(const sf::Vector2f &position);
    sf::Vector2f getPosition();
    std::string getInput();
};


#endif //GUI_TEXTINPUT_H
