//  partition.hpp
//  Final Exam, Question 2
//
//  Created by Logan Heck on 7/23/25.
#ifndef PARTITION_HPP
#define PARTITION_HPP

#include <list>
using namespace std;

// Splits the list into two: less than and greater than the pivot
template <typename T>
void partition(const T& pivot, const list<T>& input,
               list<T>* less, list<T>* greater) {
    for (auto it = input.begin(); it != input.end(); ++it) {
        if (*it < pivot) {
            less->push_back(*it);
        } else if (*it > pivot) {
            greater->push_back(*it);
        }
        // equal to pivot gets skipped
    }
}

#endif
