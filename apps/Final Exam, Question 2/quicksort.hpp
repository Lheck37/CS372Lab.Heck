//  quicksort.hpp
//  Final Exam, Question 2
//
//  Created by Logan Heck on 7/23/25.
#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <list>
#include "partition.hpp"
using namespace std;

// Recursive quicksort that returns a pointer to a new sorted list
template <typename T>
list<T>* quicksort(const list<T>& input) {
    if (input.size() <= 1) {
        return new list<T>(input); // Base case
    }

    T pivot = input.front(); // Pick first element
    list<T> less;
    list<T> greater;

    partition(pivot, input, &less, &greater);

    list<T>* sortedLess = quicksort(less);
    list<T>* sortedGreater = quicksort(greater);

    list<T>* result = new list<T>();
    result->insert(result->end(), sortedLess->begin(), sortedLess->end());
    result->push_back(pivot);
    result->insert(result->end(), sortedGreater->begin(), sortedGreater->end());

    delete sortedLess;
    delete sortedGreater;

    return result;
}

#endif
