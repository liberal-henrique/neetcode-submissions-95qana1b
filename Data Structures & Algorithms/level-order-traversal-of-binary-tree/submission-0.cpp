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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        vector<TreeNode *> visited;
        queue<TreeNode *> q;
        q.push(root);
        int sizeQueue = 0;
        int elemByLevel = 0;
        int counter = 0;
        while(!q.empty()) {
            sizeQueue = q.size();
            vector<int> level(sizeQueue, 0);
            counter = 0;
            while(sizeQueue > 0) {
                TreeNode* n = q.front();
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
                level[counter] = n->val;
                visited.push_back(n);
                q.pop();
                counter++;
                sizeQueue--;
            }
            result.push_back(level);
        }
        return result;
    }
};
