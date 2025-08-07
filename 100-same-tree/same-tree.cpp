/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qq, pq;

        qq.push(q);
        pq.push(p);

        while (!qq.empty() && !pq.empty()) {
            int n = pq.size(), m = qq.size();

            if (n != m)
                return false;

            for (int i = 0; i < n; i++) {
                TreeNode* pi = pq.front();
                pq.pop();

                TreeNode* qi = qq.front();
                qq.pop();

                // See if the nodes are same
                if (pi && qi) {
                    if (pi->val != qi->val)
                        return false;

                    if (pi->left && qi->left) { // Check the left child
                        if (pi->left->val != qi->left->val)
                            return false;
                    } else if (pi->left || qi->left)
                        return false;

                    if (pi->right && qi->right) { // check the right child
                        if (pi->right->val != qi->right->val)
                            return false;
                    } else if (pi->right || qi->right)
                        return false;

                    if (pi->left)
                        pq.push(pi->left);
                    if (qi->left)
                        qq.push(qi->left);

                    if (pi->right)
                        pq.push(pi->right);
                    if (qi->right)
                        qq.push(qi->right);
                } else if (pi || qi)
                    return false;
            }
        }

        return true;
    }
};