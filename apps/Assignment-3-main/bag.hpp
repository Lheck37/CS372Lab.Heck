// bag.hpp
#ifndef BAG_HPP
#define BAG_HPP

#include "list.hpp"

template <typename T>
class bag {
private:
    list<T> items;

public:
    void add(const T& item) {
        items.push_back(item);
    }

    void show() const {
        items.print();
    }
};

#endif // BAG_HPP
