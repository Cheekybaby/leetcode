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
    bool traversal(TreeNode* p, TreeNode* q){
        if (p == nullptr || q == nullptr){
            return p == q;
        }
        if (p->val != q->val){
            return false;
        }

        return traversal(p->left, q->right) && traversal(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        return traversal(root->left, root->right);
    }
};