// Vector.hpp
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T* data;
    size_t capacity;
    size_t length;

    void resize() {
        size_t newCapacity = capacity * 2;
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < length; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Vector() {
        capacity = 1;
        length = 0;
        data = new T[capacity];
    }

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (length == capacity) {
            resize();
        }
        data[length++] = value;
    }

    size_t size() const {
        return length;
    }

    T& operator[](size_t index) {
        return data[index];
    }
};

#endif
