//
// Created by Jose Holguin on 5/15/24.
//

#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H
#include "GuiComponent.h"
#include "FontManager.h"
#include "History.h"

class Button : public GuiComponent{
private:
    Snapshot currentSnapshot;
    sf::Text label;
    sf::RectangleShape box;
    void centerText();
public:
    Button();
    Button(float size, sf::Vector2f position, std::string label);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setLabel(std::string text);
    void setSize(sf::Vector2f size);
    sf::FloatRect getSize();
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
};

#endif //GUI_BUTTON_H
