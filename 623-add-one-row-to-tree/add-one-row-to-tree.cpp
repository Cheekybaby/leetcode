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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == nullptr) return root;
        if (depth == 1){
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }

        return adding(root, val, depth, 1);
    }

    TreeNode* adding(TreeNode *root, int val, int depth, int current){
        if (root == nullptr) return root;
        if (current == depth-1){
            TreeNode *left = root->left;
            TreeNode *right = root->right;

            root->left = new TreeNode(val, left, nullptr);
            root->right = new TreeNode(val, nullptr, right);
            return root;
        }

        root->left = adding(root->left, val, depth, current+1);
        root->right = adding(root->right, val, depth, current+1);

        return root;
    }
};