#include <iostream>
#include <chrono>
#include "Vector.hpp"
#include "Array.hpp"
#include "ReceiptBag.hpp"
using namespace std;

int main() {
    // Test Vector timing
    Vector<int> v;
    for (int i = 0; i < 1024; ++i) {
        v.push_back(i);
    }
    cout << "Vector size: " << v.size() << endl;

    // Test Array
    Array<int, 5> a;
    for (int i = 0; i < 5; ++i) {
        a[i] = i * 10;
    }
    cout << "Array contents: ";
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Test ReceiptBag
    ReceiptBag<string> bag;
    int r1 = bag.insert("apple");
    int r2 = bag.insert("banana");
    bag.print();
    cout << "Removed: " << bag.remove(r1) << endl;
    bag.print();

    return 0;
}
