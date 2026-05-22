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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root)
            return result;
        
        for (int leftItem : postorderTraversal(root->left))
            result.emplace_back(leftItem);
        for (int rightItem : postorderTraversal(root->right))
            result.emplace_back(rightItem);
        result.emplace_back(root->val);
        return result;
    }
};