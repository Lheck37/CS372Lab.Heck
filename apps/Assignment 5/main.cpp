//
//  main.cpp
//  Assignment 5
//
//  Created by Logan Heck on 6/30/25.
//
#include <iostream>
#include "List.hpp"
#include "TreeNode.hpp"
#include "traversal.hpp"
#include "prune.hpp"

int main() {
    // Test List
    std::cout << "=== Testing Smart Pointer List ===\n";
    List<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    std::cout << "Forward: ";
    myList.print_forward();

    std::cout << "Reverse: ";
    myList.print_reverse();

    // Build Tree
    std::cout << "\n=== Building Tree ===\n";
    auto root = std::make_shared<TreeNode<int>>(1);
    auto left = root->add_left(2);
    auto right = root->add_right(3);
    left->add_left(4);
    left->add_right(5);
    right->add_right(6);

    // Traverse Tree
    std::cout << "Level-order traversal:\n";
    level_order<int>(root, [](const std::shared_ptr<TreeNode<int>>& node) {
        std::cout << node->data << " ";
    });
    std::cout << "\n";

    // Prune Tree
    std::cout << "Pruned tree (no leaves):\n";
    auto pruned = prune(root);
    level_order<int>(pruned, [](const std::shared_ptr<TreeNode<int>>& node) {
        std::cout << node->data << " ";
    });
    std::cout << "\n";

    return 0;
}
