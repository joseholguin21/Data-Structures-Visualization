//
// Created by Jose Holguin on 5/30/24.
//

#ifndef GUI_HASHANIMATION_H
#define GUI_HASHANIMATION_H
#include "Animations.h"
#include "HashTable.h"

class HashAnimation : public Animations{
private:
    HashTable table;
    TitleCard title;
    TextInput remove_textbox;
    TextInput insertkey_textbox;
    TextInput insertdata_textbox;
    Button clear_button;
    sf::FloatRect window_dimensions;
    sf::RenderWindow window;
    void remove(std::string key);
    void insert(const std::pair<int, int>& record);
public:
    HashAnimation(sf::RenderWindow &window);
    //virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void draw(sf::RenderWindow& window);
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
};


#endif //GUI_HASHANIMATION_H
