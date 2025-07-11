//
//  test.cpp
//  Assignment 8
//
//  Created by Logan Heck on 7/11/25.
// test.cpp
// Test driver for HashTable — Assignment 08
#include "hashtable.h"
#include <iostream>
#include <functional>

int main() {
    HashTable table;

    // Insert several keys that will cause collisions (same mod 11)
    int keys[] = {11, 22, 33, 44, 55};
    for (int k : keys) {
        RecordType r;
        r.key = k;
        r.value = "val" + std::to_string(k);
        table.insert(r);
    }

    std::cout << "After linear inserts:\n";
    table.printTable();

    // Test default linear probing (no custom probe passed)
    RecordType result;
    bool found;
    table.find(33, found, result);
    std::cout << "Linear probe - Find 33: " << (found ? result.value : "Not found") << "\n";

    // Test quadratic probing
    table.find(33, found, result,
        std::bind(&HashTable::quadraticProbe, &table,
                  std::placeholders::_1,
                  std::placeholders::_2,
                  std::placeholders::_3));
    std::cout << "Quadratic probe - Find 33: " << (found ? result.value : "Not found") << "\n";

    // Test second hash probing
    table.find(33, found, result,
        std::bind(&HashTable::secondHash, &table,
                  std::placeholders::_1,
                  std::placeholders::_2,
                  std::placeholders::_3));
    std::cout << "Double hash probe - Find 33: " << (found ? result.value : "Not found") << "\n";

    return 0;
}
