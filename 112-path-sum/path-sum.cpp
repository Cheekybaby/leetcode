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
        if (root == nullptr) return false;

        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode *curr = q.front().first;
                int val = q.front().second;
                q.pop();
                
                if(val == targetSum && (
                    !curr->left && !curr->right
                )) return true;

                if (curr->left) q.push({curr->left, curr->left->val + val});
                if (curr->right) q.push({curr->right, curr->right->val + val});
            }
        }

        return false;
    }
};