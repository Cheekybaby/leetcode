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
class FindElements {
public:
    unordered_set<int> seen;
    FindElements(TreeNode* root) {
        root->val = 0;
        seen.insert(0);
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left) {
                    curr->left->val = curr->val * 2 + 1;
                    seen.insert(curr->left->val);
                    q.push(curr->left);
                }
                if (curr->right) {
                    curr->right->val = curr->val * 2 + 2;
                    seen.insert(curr->right->val);
                    q.push(curr->right);
                }
            }
        }
    }
    
    bool find(int target) {
        return (seen.count(target) == 1);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */