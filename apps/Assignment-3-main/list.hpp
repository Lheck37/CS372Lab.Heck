// list.hpp
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
using namespace std;

template <typename T>
class list {
private:
    struct node {
        T data;
        node* next;
        node* prev;
        node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    node* head;
    node* tail;

    void clear() {
        node* current = head;
        while (current) {
            node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }

    void copy_from(const list& other) {
        node* current = other.head;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }

public:
    list() : head(nullptr), tail(nullptr) {}

    list(const list& other) : head(nullptr), tail(nullptr) {
        copy_from(other);
    }

    list(list&& other) noexcept : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
    }

    list& operator=(const list& other) {
        if (this != &other) {
            clear();
            copy_from(other);
        }
        return *this;
    }

    list& operator=(list&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            other.head = nullptr;
            other.tail = nullptr;
        }
        return *this;
    }

    ~list() {
        clear();
    }

    void push_back(const T& value) {
        node* new_node = new node(value);
        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    void print() const {
        node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

#endif // LIST_HPP
