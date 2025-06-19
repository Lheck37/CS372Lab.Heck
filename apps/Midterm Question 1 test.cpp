//
//  test.cpp
//  Midterm question 1
//
//  Created by Logan Heck on 6/18/25.
//
#include "list.hpp"
#include <string>
using namespace std;

int main() {
    List<string> words;

    words.push_back("one");
    words.push_back("two");
    words.push_back("three");
    words.push_back("four");

    cout << "Original list: ";
    words.print();
    words.status();

    // Mark "two" and "three" as deleted
    words.lazyDelete("two");
    words.lazyDelete("three");

    cout << "After lazy deletion: ";
    words.print();
    words.status();

    // Clean up deleted nodes
    words.cleanup();

    cout << "After cleanup: ";
    words.print();
    words.status();

    return 0;
}
