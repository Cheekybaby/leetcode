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
private:
    void reverse(vector<vector<int>> &t){
        int i=0, j=t.size()-1;
        while(i < j){
            swap(t[i], t[j]);
            i++; j--;
        }
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> traversal;
        if (root == nullptr) return traversal;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> level(n);
            for(int i=0; i<n; i++){
                TreeNode *node = q.front();
                q.pop();

                level[i] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            traversal.push_back(level);
        }

        reverse(traversal);

        return traversal;
    }
};