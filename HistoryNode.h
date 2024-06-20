//
// Created by Jose Holguin on 4/11/24.
//

#ifndef GUI_HISTORYNODE_H
#define GUI_HISTORYNODE_H
#include "Snapshot.h"
#include "GuiComponent.h"

struct HistoryNode {
    Snapshot snap;
    GuiComponent *component = nullptr;
};
#endif //GUI_HISTORYNODE_H
