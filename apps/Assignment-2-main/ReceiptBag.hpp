// ReceiptBag.hpp
#ifndef RECEIPTBAG_HPP
#define RECEIPTBAG_HPP

#include <iostream>
#include "Vector.hpp"
using namespace std;

template <typename T>
class ReceiptBag {
private:
    Vector<T> items;
    Vector<int> receipts;
    int nextReceipt = 1;

public:
    int insert(const T& item) {
        items.push_back(item);
        receipts.push_back(nextReceipt);
        return nextReceipt++;
    }

    T remove(int receipt) {
        for (size_t i = 0; i < receipts.size(); ++i) {
            if (receipts[i] == receipt) {
                T removed = items[i];
                // Remove by shifting
                for (size_t j = i; j < receipts.size() - 1; ++j) {
                    receipts[j] = receipts[j + 1];
                    items[j] = items[j + 1];
                }
                receipts = shrink(receipts);
                items = shrink(items);
                return removed;
            }
        }
        throw runtime_error("Invalid receipt");
    }

    Vector<T> shrink(Vector<T>& vec) {
        Vector<T> newVec;
        for (size_t i = 0; i < vec.size() - 1; ++i) {
            newVec.push_back(vec[i]);
        }
        return newVec;
    }

    void print() const {
        for (size_t i = 0; i < items.size(); ++i) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

#endif
