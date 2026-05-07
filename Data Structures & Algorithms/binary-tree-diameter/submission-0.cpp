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
    private:
        int currentLongestPath = 0;

    public:
        void updateLongestPath(int newLongestPath, int& currentLongestPath) {
            if (newLongestPath > currentLongestPath)
                currentLongestPath = newLongestPath;
        }

        int helper(TreeNode* root) {
            if (root == NULL)
                return 0;

            int longestRight = helper(root->right);
            int longestLeft = helper(root->left);
            updateLongestPath((longestRight + longestLeft), currentLongestPath);

            if (longestLeft > longestRight)
                return 1 + longestLeft;
            else 
                return 1 + longestRight;
        }

        int diameterOfBinaryTree(TreeNode* root) {
            helper(root);
            return currentLongestPath;
        }
};
