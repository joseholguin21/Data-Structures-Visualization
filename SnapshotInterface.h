//
// Created by Jose Holguin on 4/10/24.
//

#ifndef GUI_SNAPSHOTINTERFACE_H
#define GUI_SNAPSHOTINTERFACE_H
#include "Snapshot.h"

class SnapshotInterface{
private:
public:
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //GUI_SNAPSHOTINTERFACE_H
