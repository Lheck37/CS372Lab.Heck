//  prune.hpp
//  Assignment 5
//
//  Created by Logan Heck on 6/30/25.
//
#pragma once
#include <memory>
#include "treenode.hpp"

template<typename T>
std::shared_ptr<TreeNode<T>> prune(const std::shared_ptr<TreeNode<T>>& node) {
    if (!node) return nullptr;

    // If it's a leaf node, return nullptr
    if (!node->left && !node->right) return nullptr;

    // Otherwise, create a new node with the same data
    auto newNode = std::make_shared<TreeNode<T>>(node->data);

    // Recursively prune children
    newNode->left = prune(node->left);
    if (newNode->left) newNode->left->parent = newNode;

    newNode->right = prune(node->right);
    if (newNode->right) newNode->right->parent = newNode;

    return newNode;
}
