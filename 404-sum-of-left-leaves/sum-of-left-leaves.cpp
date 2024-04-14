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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }

        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});
        int sum = 0;
        while (!q.empty()){
            TreeNode *node = q.front().first;
            bool isLeft = q.front().second;
            q.pop();

            if (isLeft && !node->left && !node->right){
                sum+=node->val;
            }

            if (node->left){
                q.push({node->left, true});
            }
            if (node->right){
                q.push({node->right, false});
            }
        }
        return sum;
    }
};