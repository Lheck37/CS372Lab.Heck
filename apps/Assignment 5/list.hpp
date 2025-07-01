//
//  list.hpp
//  Assignment 5
//
//  Created by Logan Heck on 6/30/25.
//
#pragma once
#include <iostream>
#include <memory>

template<typename T>
class List {
private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;

        Node(const T& value) : data(value), next(nullptr), prev() {}
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    void push_back(const T& value) {
        auto newNode = std::make_shared<Node>(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print_forward() const {
        auto current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void print_reverse() const {
        auto current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev.lock();
        }
        std::cout << std::endl;
    }
};
