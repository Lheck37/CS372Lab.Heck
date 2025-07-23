//  main.cpp
//  Final Exam, Question 2
//
//  Created by Logan Heck on 7/23/25.
//
#include <iostream>
#include <list>
#include "quicksort.hpp"
using namespace std;

// Builds a sample list and sorts it
int main() {
    list<int> nums = {7, 3, 9, 1, 6, 2, 5};

    list<int>* sorted = quicksort(nums);

    cout << "Sorted list: ";
    for (int num : *sorted) {
        cout << num << " ";
    }
    cout << endl;

    delete sorted;

    return 0;
}
