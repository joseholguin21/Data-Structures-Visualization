//
// Created by Jose Holguin on 5/7/24.
//

#ifndef HASHTABLE_RECORD_H
#define HASHTABLE_RECORD_H
#include <iostream>
#include "LinkedNode.h"

struct Record {
    int key;
    int value;
    LinkedNode node;
};

#endif //HASHTABLE_RECORD_H
