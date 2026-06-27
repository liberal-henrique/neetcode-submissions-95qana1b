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
    TreeNode* getBiggestLeftChild(TreeNode* root) {
        if (!root)
            return nullptr;
        
        if (root->right)
            root = getBiggestLeftChild(root->right);
        return root;
    }

    TreeNode* deleteBiggestLeftChild(TreeNode* root) {
        if (!root)
            return nullptr;

        if (!root->right)
            return root->left;
        root->right = deleteBiggestLeftChild(root->right);
        return root;
    }

    //the deepest left->right child
    TreeNode* replaceNode(TreeNode* root) {
        if (!root)
            return nullptr;

        if (root->left && !root->right) {
            return root->left;
        } 
        if (!root->left && root->right) {
            return root->right;
        } 
        if (root->left && root->right) {
            TreeNode* newValue = getBiggestLeftChild(root->left);
            root->val = newValue->val;
            root->left = deleteBiggestLeftChild(root->left);
            return root;
        } 
        return nullptr;
    }

    TreeNode* deleteNode(TreeNode *root, int key) {
        if (!root)
            return nullptr;

        if (root->val == key) {
            return replaceNode(root);
        }
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

};