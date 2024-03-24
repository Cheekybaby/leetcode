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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int x = temp.second.first, y = temp.second.second;
            mpp[x][y].insert(node->val);

            if (node->left){
                q.push({node->left, {x-1, y+1}});
            }
            if (node->right){
                q.push({node->right, {x+1, y+1}});
            }
        }

        vector<vector<int>> ans;
        for (auto mp:mpp){
            vector<int> v;
            for(auto it:mp.second){
                v.insert(v.end(), it.second.begin(), it.second.end());
            }
            ans.push_back(v);
        }

        return ans;
    }
};