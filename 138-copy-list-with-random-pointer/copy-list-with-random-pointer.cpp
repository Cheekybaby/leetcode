/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodes;
        Node *temp = head;
        while(temp){
            nodes[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp){
            Node *new_node = nodes[temp];
            new_node->next = nodes[temp->next];
            new_node->random = nodes[temp->random];
            temp = temp->next;
        }

        return nodes[head];
    }
};