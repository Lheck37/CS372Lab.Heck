// test.cpp
#include "list.hpp"
#include "bag.hpp"
#include <string>
#include <iostream>
using namespace std;

int main() {
    list<string> words;
    words.push_back("hello");
    words.push_back("world");
    words.push_back("!");

    cout << "Words: ";
    words.print();

    bag<int> numbers;
    numbers.add(5);
    numbers.add(10);
    numbers.add(15);

    cout << "Numbers in bag: ";
    numbers.show();

    return 0;
}
