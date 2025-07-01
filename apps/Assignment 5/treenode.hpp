//  Created by Logan Heck on 6/30/25.
//
#pragma once
#include <iostream>
#include <memory>

template<typename T>
class TreeNode : public std::enable_shared_from_this<TreeNode<T>> {
public:
    T data;
    std::shared_ptr<TreeNode<T>> left;
    std::shared_ptr<TreeNode<T>> right;
    std::weak_ptr<TreeNode<T>> parent;

    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr), parent() {}

    std::shared_ptr<TreeNode<T>> add_left(const T& value) {
        left = std::make_shared<TreeNode<T>>(value);
        left->parent = this->shared_from_this();
        return left;
    }

    std::shared_ptr<TreeNode<T>> add_right(const T& value) {
        right = std::make_shared<TreeNode<T>>(value);
        right->parent = this->shared_from_this();
        return right;
    }
};
