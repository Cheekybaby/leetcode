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
        if (root == nullptr){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()){
            int count = q.size();
            for (int i=0; i<count; i+=1){
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left != nullptr){
                    q.push(temp->left);
                }
                if (temp->right != nullptr){
                    q.push(temp->right);
                }
            }
            ans+=1;
        }

        return ans;
    }
};