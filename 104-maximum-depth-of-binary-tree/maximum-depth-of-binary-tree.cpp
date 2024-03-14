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
    int maxDepth(TreeNode* root) {
        // Iteravtive DFS
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int ans = 0;
        while (!st.empty()){
            pair<TreeNode*, int> p;
            p = st.top();
            TreeNode *node = p.first;
            int depth = p.second;
            st.pop();
            if (node!=nullptr){
                ans = max(ans, depth);
                st.push({node->left, depth+1});
                st.push({node->right, depth+1});
            }
        }

        return ans;
    }
};