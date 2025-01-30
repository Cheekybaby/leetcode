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
    void reverse(vector<int> &f){
        int i=0, j=f.size()-1;
        while(i < j){
            swap(f[i], f[j]);
            i+=1;
            j-=1;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);
        
        int l = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i=0; i<n; i++){
                TreeNode *curr = q.front();
                q.pop();
                
                level.push_back(curr->val);
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(l % 2) reverse(level);
            ans.push_back(level);
            l+=1;
        }

        return ans;
    }
};