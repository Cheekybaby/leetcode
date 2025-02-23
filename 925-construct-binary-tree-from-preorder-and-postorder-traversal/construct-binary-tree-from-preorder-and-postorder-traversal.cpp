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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int preIndex = 0, postIndex = 0;
        return tree(preIndex, postIndex, preorder, postorder);
    }

private:
    TreeNode* tree(int& preIndex, int& postIndex, vector<int> &pre, vector<int> &post) {
        TreeNode *root = new TreeNode(pre[preIndex]);
        preIndex++;

        if (root->val != post[postIndex]){
            root->left = tree(preIndex, postIndex, pre, post);
        }

        if (root->val != post[postIndex]){
            root->right = tree(preIndex, postIndex, pre, post);
        }

        postIndex++;

        return root;
    }
};