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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        stack<TreeNode*> st;
        if (root == nullptr) return traversal;
        TreeNode *curr = root;
        while (curr != nullptr || !st.empty()){
            while (curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            traversal.push_back(curr->val);
            curr = curr->right;
        }

        return traversal;
    }
};