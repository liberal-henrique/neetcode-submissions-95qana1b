/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool compareAllTheNode(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;

        if ((!root || !subRoot))
            return false;
        if (root->val != subRoot->val)
            return false;
        bool leftChild = compareAllTheNode(root->left, subRoot->left);
        bool rightChild = compareAllTheNode(root->right, subRoot->right);

        return leftChild && rightChild;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;

        if (compareAllTheNode(root, subRoot))
            return true;
        
        bool leftChild = isSubtree(root->left, subRoot);
        bool rightChild = isSubtree(root->right, subRoot);

        return leftChild || rightChild;
    }
};
