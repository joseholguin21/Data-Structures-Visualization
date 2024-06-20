//
// Created by Jose Holguin on 4/10/24.
//

#ifndef GUI_GUICOMPONENT_H
#define GUI_GUICOMPONENT_H
#include <iostream>
#include "SnapshotInterface.h"
#include "Snapshot.h"
#include "States.h"
#include "EventHandler.h"
#include "MouseEvents.h"
#include "KeyboardShortcuts.h"


class GuiComponent : public EventHandler, public States, public SnapshotInterface, public sf::Drawable
{
private:
public:
//from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

// from EventHandler
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

//from SnapshotInterface
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //GUI_GUICOMPONENT_H
