//
// Created by Jose Holguin on 4/11/24.
//

#include "History.h"

std::stack<HistoryNode> History::stack;

void History::pushHistory(const HistoryNode &snapshot) {
   stack.push(snapshot);
}

HistoryNode &History::topHistory() {
    return stack.top();
}

void History::popHistory() {
    stack.pop();
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {
}

bool History::isEmpty() {
    return stack.empty();
}
