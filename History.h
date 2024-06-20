//
// Created by Jose Holguin on 4/11/24.
//

#ifndef GUI_HISTORY_H
#define GUI_HISTORY_H
#include "HistoryNode.h"
#include <stack>

class History  {
private:
    static std::stack<HistoryNode> stack;
public:
    //static std::stack<HistoryNode> stack;
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
    static bool isEmpty();

};

#endif //GUI_HISTORY_H
