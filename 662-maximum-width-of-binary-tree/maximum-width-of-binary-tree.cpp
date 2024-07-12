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
 # define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ll ans = 0;

        if (root == nullptr) return ans;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()){
            ll pos = q.front().second;
            int n = q.size();

            ll first, last;
            for (int i=0; i<n; i+=1){
                ll curr_idx = q.front().second - pos;
                TreeNode *curr_node = q.front().first;
                q.pop();
                if (i == 0){
                    first = curr_idx;
                } 
                if (i == n-1) {
                    last = curr_idx;
                }

                if (curr_node->left) q.push({curr_node->left, curr_idx*2+1});
                if (curr_node->right) q.push({curr_node->right, curr_idx*2+2});
            }
            ans = max(ans, last-first+1);
        }

        return ans;
    }
};