//  test.cpp
//  Midterm question 2
//
//  Created by Logan Heck on 6/18/25.
//
#include <iostream>
#include "Vector.hpp"
using namespace std;

int main() {
    Vector<string> words;
    words.push_back("hello");
    words.push_back("world");
    words.push_back("iterator");

    cout << "Words using iterator: ";
    for (auto it = words.begin(); it != words.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
