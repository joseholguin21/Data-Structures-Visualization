//
// Created by Jose Holguin on 4/10/24.
//

#include "States.h"

States::States() {

    for (int i=0; i < LASTSTATE; i++)
        states[static_cast<StateEnum>(i)] = false;
}

bool States::checkState(StateEnum state) const {
    return states.at(state);
}

void States::enableState(StateEnum state) {
    states[state] = true;
}

void States::disableState(StateEnum state) {
    states[state] = false;
}

void States::toggleState(StateEnum state) {
    states[state] = !states[state];
}

std::map<StateEnum, bool> States::getStatesMap() {
    return states;
}

void States::setStatesMap(std::map<StateEnum, bool> states) {

    for (int i=0; i < LASTSTATE; i++)
        this->states[static_cast<StateEnum>(i)] = states[static_cast<StateEnum>(i)];
}
