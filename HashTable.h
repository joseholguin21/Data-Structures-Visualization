//
// Created by Jose Holguin on 5/7/24.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H
#include <iostream>
#include <vector>
#include "Record.h"
#include <initializer_list>
#include "TitleCard.h"
#include <algorithm>

class HashTable : public sf::Drawable{
private:
    static const int CAPACITY = 11;
    //allrecords stores the nodes
    std::vector<Record> allrecords;

    std::vector<TitleCard> indexes;

    std::vector<Record> data[CAPACITY];
    int total_records = 0;
    int hash(int key);
    void binary_search(std::vector<Record>, std::size_t first, std::size_t size, int target, bool &found, int& location);
    void quick_sort(Record *data, std::size_t size);
    void partition(Record *data, int size, int& pivot_index);
    void storerecords();
public:
    typedef typename std::vector<Record>::iterator iterator;
    HashTable();
    HashTable(const std::initializer_list<std::pair<int, int>>& list);
    void insert(int key, const int& value);
    void insert(const std::pair<int, int>& record);
    int& operator[](unsigned int key); ///throw an exception, then crash if key doesn't exist
    int& at(unsigned int key); ///throw an exception
    int size();
    bool empty();
    ////iterator
    iterator begin();
    iterator end();
    int count(int key); ///return the number of keys that equal key in the map
    bool contains(int key); ///returns true if the key exist
    void remove(int key);
    void find(int key, bool& found, int& index);
    void clear();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //void draw(sf::RenderWindow& window);
};

#endif //HASHTABLE_HASHTABLE_H
