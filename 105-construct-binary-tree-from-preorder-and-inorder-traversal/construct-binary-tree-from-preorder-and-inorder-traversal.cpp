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
    TreeNode *tree(vector<int> &preorder, int pstart, int pend, vector<int> &inorder, int instart, int inend, map<int,int> &mpp){
        if (instart > inend || pstart > pend){
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[pstart]);
        int inroot = mpp[root->val];
        int nleft = inroot - instart;

        root->left = tree(preorder, pstart+1, pstart+nleft, inorder, instart, inroot-1, mpp);
        root->right = tree(preorder, pstart+nleft+1, pend, inorder, inroot+1, inend, mpp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        for (int i=0; i<inorder.size(); i+=1){
            mpp[inorder[i]] = i;
        }

        TreeNode *root = tree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);
        return root;
    }
};