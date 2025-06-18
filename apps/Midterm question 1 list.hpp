//
//  list.hpp
//  Midterm question 1
//
//  Created by Logan Heck on 6/18/25.
//
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        bool isDeleted;

        Node(const T& value) : data(value), next(nullptr), prev(nullptr), isDeleted(false) {}
    };

    Node* head;
    Node* tail;
    int activeCount;
    int deletedCount;

public:
    List() : head(nullptr), tail(nullptr), activeCount(0), deletedCount(0) {}

    ~List() {
        clear();
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        activeCount++;
    }

    void lazyDelete(const T& value) {
        Node* current = head;
        while (current) {
            if (current->data == value && !current->isDeleted) {
                current->isDeleted = true;
                deletedCount++;
                activeCount--;
                break;
            }
            current = current->next;
        }
    }

    void cleanup() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            if (current->isDeleted) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                delete current;
                deletedCount--;
            }
            current = nextNode;
        }
    }

    void print() const {
        Node* current = head;
        while (current) {
            if (!current->isDeleted) {
                cout << current->data << " ";
            }
            current = current->next;
        }
        cout << endl;
    }

    void status() const {
        cout << "Active: " << activeCount << ", Deleted: " << deletedCount << endl;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
        activeCount = deletedCount = 0;
    }
};

#endif

