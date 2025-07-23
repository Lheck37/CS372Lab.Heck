//  treefunctions.hpp
//  Final Exam, Question 1
//
//  Created by Logan Heck on 7/23/25.
//
#ifndef TREEFUNCTIONS_HPP
#define TREEFUNCTIONS_HPP

#include "TreeNode.hpp"

int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countInternalNodes(TreeNode* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return 0;
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

void externalPathLength(TreeNode* root, int depth, int& sum) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
        sum += depth;
        return;
    }
    externalPathLength(root->left, depth + 1, sum);
    externalPathLength(root->right, depth + 1, sum);
}

#endif
