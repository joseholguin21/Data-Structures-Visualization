//
// Created by Jose Holguin on 4/10/24.
//

#ifndef GUI_STATES_H
#define GUI_STATES_H
#include <SFML/Graphics.hpp>
#include <map>
#include "StateEnum.h"

class States {
private:
    std::map<StateEnum, bool> states;

public:
     States();
     bool checkState(StateEnum state) const;
     void enableState(StateEnum state);
     void disableState(StateEnum state);
     void toggleState(StateEnum state);
     std::map<StateEnum, bool> getStatesMap();
     void setStatesMap(std::map<StateEnum, bool> states);
};


#endif //GUI_STATES_H
