//
// Created by Jose Holguin on 5/7/24.
//
#include "HashTable.h"

int HashTable::hash(int key) {
    return key%CAPACITY;
}

HashTable::HashTable() {
    float y=100;
    float x=0;
    TitleCard first(30, {x, y}, std::to_string(0));
    indexes.push_back(first);
    for (int i=1; i < CAPACITY; i++) {
        TitleCard t(40, {indexes[i-1].getPosition().x, indexes[i-1].getPosition().y + indexes[i-1].getGlobalBounds().height}, std::to_string(i));
        indexes.push_back(t);
    }
}

HashTable::HashTable(const std::initializer_list<std::pair<int , int>> &list) {
    for (const auto& pair : list) {
        insert({pair.first, pair.second});
    }
}

void HashTable::insert(int key, const int &value) {
  int hashkey = hash(key);
  int index;
  bool found;
  //std::cout << hashkey;
  find(key, found, index);
  if (!found) {
      //pushback new record
      Record record;
      record.key = key;
      record.value = value;
      data[hashkey].push_back(record);
      total_records++;
      quick_sort(&data[hashkey][0], data[hashkey].size());
  }
  else {
      //overwrite value
      data[hashkey][index].value = value;
  }
  storerecords();

}


void HashTable::insert(const std::pair<int, int>& record) {
    insert(record.first, record.second);
}


int &HashTable::operator[](unsigned int key){
    bool found;
    int index;
    int hashkey = hash(key);

    find(key, found, index);

    if (found)
        return data[hashkey][index].value;
    else {
        data[hashkey].emplace_back();
        data[hashkey].back().key = key;
        int& value = data[index].back().value;
        quick_sort(&data[hashkey][0], data[hashkey].size());
        return value;
    }

}


int &HashTable::at(unsigned int key) {
    return (*this)[key];
}


int HashTable::size() {
    return total_records;
}

bool HashTable::empty() {
    return data->empty();
}



typename HashTable::iterator HashTable::begin() {

    return allrecords.begin();
}


typename HashTable::iterator HashTable::end() {

    return allrecords.end();
}


int HashTable::count(int key) {
    if (contains(key))
        return 1;
    else
        return 0;
}


bool HashTable::contains(int key) {
    int hashkey = hash(key);
    bool found;
    int index;
    binary_search(data[hashkey], 0, data[hashkey].size(), key, found, index);

    return found;
}


void HashTable::remove(int key) {
    int hashkey = hash(key);
    int index;
    bool found;

    binary_search(data[hashkey], 0, data[hashkey].size(), key, found, index);

    if (found) {
        std::swap(data[hashkey][index], data[hashkey][data[hashkey].size()-1]);
        data[hashkey].pop_back();
        quick_sort(&data[hashkey][0], data[hashkey].size());
    }
    else {
        std::cout << "not found";
    }

    total_records--;

    storerecords();
}


void HashTable::find(int key, bool &found, int &index) {
    //int hashkey = key;
    int hashkey = hash(key);

    binary_search(data[hashkey], 0, data[hashkey].size(), key, found, index);
    if (!found) {
        index = -1;
    }
}


void HashTable::binary_search(std::vector<Record> a, std::size_t first, std::size_t size, int key, bool &found,
                                 int &location) {
    ///base case or stopping case
    if (size == 0) {
        found = false;
    }
    else {
        ///calculate middle index
        std::size_t middleIndex = first + size/2;

        if (a[middleIndex].key == key) {
            found = true;
            location = middleIndex;
        }
        else {
            if (key < a[middleIndex].key) {
                //search left
                binary_search(a, first, size/2, key, found, location);
            }
            else {
                //search right
                binary_search(a, middleIndex+1, (size-1)/2,  key, found, location);
            }
        }
    }
}


void HashTable::quick_sort(Record *data, std::size_t size) {
    int pivot_index;
    int left_size;
    int right_size;

    if (size > 1) {
        partition(data, size, pivot_index);
        left_size = pivot_index;
        right_size = size - pivot_index - 1;
        quick_sort(data, left_size);
        quick_sort(data+pivot_index + 1, right_size);
    }
}


void HashTable::partition(Record *data, int size, int& pivot_index) {
    int pivot = data[0].key;
    int i = 1;
    int j = size-1;

    while (i <= j) {
        while (data[i].key <= pivot && i < size) {
            i++;
        }
        while (data[j].key > pivot) {
            j--;
        }
        if (i < j) {
            std::swap(data[i], data[j]);
        }
    }

    pivot_index = j;
    std::swap(data[pivot_index], data[0]);
    data[pivot_index].key = pivot;

}



void HashTable::storerecords() {
    allrecords.clear();

    for (int i=0; i < CAPACITY; i++) {
        if (!data[i].empty()) {
            for (int j=0; j < data[i].size(); j++) {
                if (j == 0) {
                    //LinkedNode n({50, 50}, {75, (float)i*75}, std::to_string(data[i][j].value), std::to_string(data[i][j].key));
                    LinkedNode n({50, 35}, {indexes[i].getGlobalBounds().left + indexes[i].getGlobalBounds().width + 75, indexes[i].getGlobalBounds().top + indexes[i].getGlobalBounds().height/2},
                                 std::to_string(data[i][j].value), std::to_string(data[i][j].key));
                    data[i][j].node = n;
                }
                else {
                    sf::FloatRect dimensions = data[i][j-1].node.getBounds();
                    LinkedNode n({50, 35}, {data[i][j-1].node.getPosition().x + dimensions.width, data[i][j-1].node.getPosition().y },
                                     std::to_string(data[i][j].value), std::to_string(data[i][j].key));
                    //LinkedNode n({50, 50}, {data[i][j-1].node.getPosition().x + dimensions.width, indexes[i].getGlobalBounds().top},
//                                     std::to_string(data[i][j].value), std::to_string(data[i][j].key));
                    data[i][j].node = n;
                }
                allrecords.push_back(data[i][j]);

                }
            }
        }
}


void HashTable::clear() {
    allrecords.clear();
    for (int i=0; i < CAPACITY; i++) {
        if (!data[i].empty()) {
            data[i].clear();
        }
    }
}

void HashTable::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    //storerecords();
    for (int i=0; i < allrecords.size(); i++) {
        window.draw(allrecords[i].node);
    }

    for (int i=0; i < indexes.size(); i++) {
        window.draw(indexes[i]);
    }
}
