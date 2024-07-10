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
    int height(TreeNode *root){
        if (root == nullptr) {
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        int left_h = height(root->left);
        int right_h = height(root->right);

        if (abs(left_h - right_h) <=1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
};