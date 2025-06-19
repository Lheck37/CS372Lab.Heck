//
//  vector.hpp
//  Midterm question 2
//
//  Created by Logan Heck on 6/18/25.
//
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

    // --- NEW: Iterator ---
    class iterator {
    private:
        Vector* vec;
        size_t index;
    public:
        iterator(Vector* v, size_t i) : vec(v), index(i) {}

        T& operator*() const {
            return (*vec)[index];
        }

        iterator& operator++() { // prefix ++
            ++index;
            return *this;
        }

        bool operator==(const iterator& other) const {
            return vec == other.vec && index == other.index;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }
    };

    iterator begin() {
        return iterator(this, 0);
    }

    iterator end() {
        return iterator(this, length);
    }
};

#endif
