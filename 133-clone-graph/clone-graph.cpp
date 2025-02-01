/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;

        unordered_map<Node*, Node*> m;

        Node *root = new Node(node->val, {});
        m[node] = root;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node *curr = q.front();
            q.pop();

            for(auto &adj:curr->neighbors){
                if(m.find(adj) == m.end()){
                    m[adj] = new Node(adj->val, {});
                    q.push(adj);
                }

                m[curr]->neighbors.push_back(m[adj]);
            }
        }

        return m[node];
    }
};