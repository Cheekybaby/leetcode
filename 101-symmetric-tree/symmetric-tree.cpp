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
    bool isPalindrome(vector<int> &val){
        int i=0, j=val.size()-1;
        while(i < j){
            if (val[i] != val[j]) return false;
            i++; j--;
        }
        return true;
    }

    bool allDummy(vector<int> &val){
        for(auto &it:val){
            if (it != -101) return false;
        }
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *dummy = new TreeNode(-101);
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> val(n);
            for(int i=0; i<n; i++){
                TreeNode *node = q.front();
                q.pop();

                val[i] = node->val;

                if (node->left){
                    q.push(node->left);
                } else {
                    q.push(dummy);
                }

                if (node->right){
                    q.push(node->right);
                } else {
                    q.push(dummy);
                }
            }
            if (!isPalindrome(val)) return false;
            
            if (allDummy(val)) break;
        }

        return true;
    }
};