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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool l2r = true;

        while (!q.empty()){
            int size = q.size();
            vector<int> row(size);

            for (int i=0; i<size; i+=1){
                TreeNode* temp = q.front();
                q.pop();
                int index = (l2r) ? i : (size-i-1);

                row[index] = temp->val;
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            l2r = !l2r;
            ans.push_back(row);
        }

        return ans;
    }
};