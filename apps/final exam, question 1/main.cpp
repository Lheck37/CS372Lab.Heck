//  main.cpp
//  Final Exam, Question 1
//
//  Created by Logan Heck on 7/23/25.
//
#include <iostream>
#include "TreeNode.hpp"
#include "TreeFunctions.hpp"

using namespace std;

TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode("A");
    root->left = new TreeNode("B");
    root->right = new TreeNode("C");
    root->left->left = new TreeNode("D");
    root->right->left = new TreeNode("E");
    root->right->right = new TreeNode("F");
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();

    cout << "Total nodes: " << countNodes(root) << endl;
    cout << "Internal nodes: " << countInternalNodes(root) << endl;

    int sum = 0;
    externalPathLength(root, 0, sum);
    cout << "External path length: " << sum << endl;

    return 0;
}
