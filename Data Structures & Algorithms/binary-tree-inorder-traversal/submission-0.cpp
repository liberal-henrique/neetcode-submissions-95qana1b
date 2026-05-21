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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> current;
        if (!root)
            return current;

        vector<int> leftChild = inorderTraversal(root->left);
        current.push_back(root->val);
        vector<int> rightChild = inorderTraversal(root->right);
        
        vector<int> result;
        for (int item : leftChild)
            result.push_back(item);
        for (int item : current)
            result.push_back(item);
        for (int item : rightChild)
            result.push_back(item);
        return result;
    }
};