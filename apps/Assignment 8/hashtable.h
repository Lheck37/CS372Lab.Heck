//
//  hashtable.h
//  Assignment 8
//
//  Created by Logan Heck on 7/11/25.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <functional>
#include <string>
#include <cstddef>

const std::size_t CAPACITY = 11; // Small on purpose to force collisions
const int NEVER_USED = -1;
const int PREVIOUSLY_USED = -2;

struct RecordType {
    int key = NEVER_USED; // Key ≥ 0 only when OCCUPIED
    std::string value = "";
};

class HashTable {
public:
    HashTable();

    void insert(const RecordType& entry);
    void remove(int key);

    void find(int key, bool& found, RecordType& result,
              std::function<void(int, bool&, std::size_t&)> probeFunc = nullptr);

    void printTable() const;

    // These must be public so test.cpp can bind them
    void findIndex(int key, bool& found, std::size_t& index);
    void quadraticProbe(int key, bool& found, std::size_t& index);
    void secondHash(int key, bool& found, std::size_t& index);

private:
    RecordType data[CAPACITY];
    std::size_t used;

    std::size_t hash(int key) const { return key % CAPACITY; }
    std::size_t nextIndex(std::size_t i) const { return (i + 1) % CAPACITY; }
    bool neverUsed(std::size_t i) const { return data[i].key == NEVER_USED; }
    bool isVacant(std::size_t i) const { return data[i].key < 0; }
};

#endif


