/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<Node*> v(n);
            for(int i=0; i<n; i++){
                Node* curr = q.front();
                q.pop();
                v[i] = curr;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            for(int i=0; i<n; i++){
                if (i == n-1){
                    Node *curr = v[i];
                    curr->next = nullptr;
                    continue;
                }
                Node *curr = v[i];
                Node *nex = v[i+1];
                curr->next = nex;
            }
        }

        return root;
    }
};