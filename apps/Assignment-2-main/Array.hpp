// Array.hpp
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
using namespace std;

template <typename T, size_t SIZE>
class Array {
private:
    T data[SIZE];

public:
    Array() {}

    T& operator[](size_t index) {
        return data[index];
    }

    size_t size() const {
        return SIZE;
    }
};

#endif
