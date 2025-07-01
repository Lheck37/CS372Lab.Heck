#pragma once
#include <queue>
#include <functional>
#include <memory>
#include "TreeNode.hpp"

template<typename T>
void level_order(const std::shared_ptr<TreeNode<T>>& root,
                 const std::function<void(const std::shared_ptr<TreeNode<T>>&)>& visit) {
    if (!root) return;

    std::queue<std::shared_ptr<TreeNode<T>>> q;
    q.push(root);

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        visit(current);

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}
