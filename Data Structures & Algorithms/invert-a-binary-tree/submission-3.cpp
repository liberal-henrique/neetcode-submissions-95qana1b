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

class Solution {
public:
    // Bottom to Top
    TreeNode* invertTree(TreeNode* root) {
        if (root != NULL && root->left == NULL && root->right == NULL)
            return root;
        if (root == NULL) 
            return NULL;
        
        if (root->left != NULL)
            invertTree(root->left);
        if (root->right != NULL)
            invertTree(root->right);

        TreeNode *swap = NULL;
        if (root->left != NULL && root->right != NULL) {
            swap = root->left;
            root->left = root->right;
            root->right = swap;
        } 
        else if (root->left == NULL) {
            root->left = root->right;
            root->right = NULL;
        }
        else if (root->right == NULL) {
            root->right = root->left;
            root->left = NULL;
        }
        return root;
    }
};
