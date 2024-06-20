//
// Created by Jose Holguin on 4/11/24.
//

#include "Snapshot.h"


Snapshot::Snapshot() {

}


void Snapshot::setText(std::string text) {
    this->text = text;
}

void Snapshot::setStates(std::map<StateEnum, bool> states) {
    objectstates = states;
}

std::map<StateEnum, bool> Snapshot::getStates() const {
    return objectstates;
}

std::string Snapshot::getText() const {
    return text;
}
