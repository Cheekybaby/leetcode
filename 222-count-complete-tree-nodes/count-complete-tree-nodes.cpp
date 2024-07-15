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
    void traversal(TreeNode* root, int &count){
        if (root == nullptr) return ;

        count+=1;
        traversal(root->right, count);
        traversal(root->left, count);
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        traversal(root, count);

        return count;
    }
};