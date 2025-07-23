//  treenode.hpp
//  Final Exam, Question 1
//
//  Created by Logan Heck on 7/23/25.
#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <string>
using namespace std;

class TreeNode {
public:
    string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

#endif
