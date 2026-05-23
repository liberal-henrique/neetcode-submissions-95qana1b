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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        valueFound += root->val;
        bool result = false;

        if (root->left == nullptr && root->right == nullptr) {
            result = (valueFound == targetSum) ? true : false; 
            valueFound -= root->val;
            return result;
        }
        
        bool leftChild = false;
        bool rightChild = false;

        if (root->left) 
            leftChild = hasPathSum(root->left, targetSum);
            
        if (root->right) 
            rightChild = hasPathSum(root->right, targetSum);
        
        
        if (leftChild || rightChild) 
            result = true;
        else if (leftChild == false) {
            valueFound -= root->val;
            result = false;
        }
        else if (rightChild == false) {
            valueFound -= root->val;
            result = false;
        }
        return result;
    }
private:
    int valueFound = 0;
};