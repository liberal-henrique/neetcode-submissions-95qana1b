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

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root)
            return result;
        
        result.push_back(root->val);
        for (int leftItem : preorderTraversal(root->left))
            result.push_back(leftItem);
        for (int rightItem : preorderTraversal(root->right))
            result.push_back(rightItem);

        return result;
    }
};