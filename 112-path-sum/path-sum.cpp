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

        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});

        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode *node = q.front().first;
                int val = q.front().second;

                q.pop();

                int sum = val + node->val;
                if (sum == targetSum && (!node->left && !node->right)) return true;

                if (node->left) q.push({node->left, sum});
                if (node->right) q.push({node->right, sum});
            }
        }

        return false;
    }
};