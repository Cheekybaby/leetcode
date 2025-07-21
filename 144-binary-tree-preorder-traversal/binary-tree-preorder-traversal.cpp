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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> traversal_path;
        if(root == nullptr) return traversal_path;
        TreeNode *curr = root;
        nodes.push(curr);
        while(!nodes.empty()){
            TreeNode *temp = nodes.top();
            nodes.pop();

            traversal_path.push_back(temp->val);

            if (temp->right) nodes.push(temp->right);
            if (temp->left) nodes.push(temp->left);
        }

        return traversal_path;
    }
};