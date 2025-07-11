// hashtable.cpp
// Implementation for HashTable class — Assignment 08

#include "hashtable.h"
#include <iostream>
#include <cassert>

/* ───── constructor ───── */
HashTable::HashTable() {
    used = 0;
    for (std::size_t i = 0; i < CAPACITY; ++i) {
        data[i].key = NEVER_USED;
    }
}

/* ───── insert ───── */
void HashTable::insert(const RecordType& entry) {
    assert(entry.key >= 0);
    bool found;
    std::size_t index;

    findIndex(entry.key, found, index);
    if (found) {
        data[index] = entry;  // update existing
        return;
    }

    // linear insert (slides)
    index = hash(entry.key);
    while (!isVacant(index)) {
        index = nextIndex(index);
    }

    data[index] = entry;
    ++used;
}

/* ───── remove ───── */
void HashTable::remove(int key) {
    bool found;
    std::size_t index;
    findIndex(key, found, index);

    if (found) {
        data[index].key = PREVIOUSLY_USED;
        --used;
    }
}

/* ───── find (default or custom probe) ───── */
void HashTable::find(int key, bool& found, RecordType& result,
                     std::function<void(int,bool&,std::size_t&)> hashingFunction) {
    if (!hashingFunction) {
        hashingFunction = std::bind(&HashTable::findIndex, this,
                                    std::placeholders::_1,
                                    std::placeholders::_2,
                                    std::placeholders::_3);
    }

    std::size_t index;
    hashingFunction(key, found, index);
    if (found) result = data[index];
}

/* ───── linear probing (default) ───── */
void HashTable::findIndex(int key, bool& found, std::size_t& index) {
    std::size_t start = hash(key);
    index = start;
    found = false;

    while (!neverUsed(index)) {
        if (data[index].key == key) {
            found = true;
            return;
        }
        index = nextIndex(index);
        if (index == start) break;
    }
}

/* ───── quadratic probing ───── */
void HashTable::quadraticProbe(int key, bool& found, std::size_t& index) {
    std::size_t start = hash(key);
    std::size_t i = 0;
    found = false;

    while (i < CAPACITY) {
        index = (start + i*i) % CAPACITY;
        if (neverUsed(index)) return;
        if (data[index].key == key) {
            found = true;
            return;
        }
        ++i;
    }
}

/* ───── double hashing ───── */
void HashTable::secondHash(int key, bool& found, std::size_t& index) {
    std::size_t h1 = hash(key);
    std::size_t h2 = 7 - (key % 7);
    std::size_t i = 0;
    found = false;

    while (i < CAPACITY) {
        index = (h1 + i * h2) % CAPACITY;
        if (neverUsed(index)) return;
        if (data[index].key == key) {
            found = true;
            return;
        }
        ++i;
    }
}

/* ───── print table contents ───── */
void HashTable::printTable() const {
    std::cout << "\nHash Table:\n";
    for (std::size_t i = 0; i < CAPACITY; ++i) {
        std::cout << "[" << i << "] ";
        if (data[i].key >= 0)
            std::cout << data[i].key << " : " << data[i].value;
        else if (data[i].key == PREVIOUSLY_USED)
            std::cout << "<deleted>";
        else
            std::cout << "<empty>";
        std::cout << "\n";
    }
    std::cout << std::endl;
}
