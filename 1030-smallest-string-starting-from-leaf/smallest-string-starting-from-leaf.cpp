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
    void traverse(TreeNode *root, string s, string &smallest){
        if (root == nullptr) return;

        s += char('a' + root->val);

        if (!root->left && !root->right){
            reverse(s.begin(), s.end());
            if (smallest.empty() || s<smallest){
                smallest = s;
            }
            reverse(s.begin(), s.end());
        }

        traverse(root->left, s, smallest);
        traverse(root->right, s, smallest);
    }
    string smallestFromLeaf(TreeNode* root) {
        string smallest;
        traverse(root, "", smallest);

        return smallest;
    }
};