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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        if (root == nullptr) return traversal;
        queue<TreeNode*> q;
        q.push(root);
        bool l_to_r = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> level(n, 0);
            for(int i=0; i<n; i++){
                TreeNode *node = q.front();
                q.pop();

                int idx = (l_to_r) ? i : n-i-1;

                level[idx] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            traversal.push_back(level);
            l_to_r = !l_to_r;
        }

        return traversal;
    }
};