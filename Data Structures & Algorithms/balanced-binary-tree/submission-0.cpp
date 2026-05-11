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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int depthLeft = 1 + maxDepth(root->left); 
        int depthRight = 1 + maxDepth(root->right);
        if (depthRight > depthLeft) 
            return depthRight;
        else 
            return depthLeft;
    }

    //Bottom to Top
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        bool balancedLeft = true;
        bool balancedRight = true;
        if (root->left != NULL)
            balancedLeft = isBalanced(root->left);
        if (root->right != NULL)
            balancedRight = isBalanced(root->right);

        bool result = true;
        if (balancedLeft == false || balancedRight == false)
            result = false;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        if (abs(rightDepth - leftDepth) > 1)
            result = false;
        return result;
    }
};
