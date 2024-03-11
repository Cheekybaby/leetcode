/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return ;
        vector<ListNode*> v;
        int len = 0, i = 0;
        ListNode *temp = head;
        while (temp){
            v.push_back(temp);
            len+=1;
            temp = temp->next;
        }
        for (i=0; i<len/2; i+=1){
            if (i==0){
                temp = v[i];
                temp->next = v[len-i-1];
                temp = temp->next;
            } else {
                temp->next = v[i];
                temp = temp->next;
                temp->next = v[len-i-1];
                temp = temp->next;
            }
        }

        if (len%2){
            temp->next = v[i];
            temp = temp->next;
        }

        temp->next = nullptr;
        return ;
    }
};