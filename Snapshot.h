//
// Created by Jose Holguin on 4/11/24.
//

#ifndef GUI_SNAPSHOT_H
#define GUI_SNAPSHOT_H
#include <SFML/Graphics.hpp>
#include "States.h"

class Snapshot{
private:
    std::map<StateEnum, bool> objectstates;
    std::string text;
public:
    Snapshot();
    void setText(std::string text);
    void setStates(std::map<StateEnum, bool> states);
    std::map<StateEnum, bool> getStates() const;
    std::string getText() const;
};


#endif //GUI_SNAPSHOT_H
