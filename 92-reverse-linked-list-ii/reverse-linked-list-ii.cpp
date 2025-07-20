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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *prev = dummy_head, *curr = head;

        for(int i=0; i<left-1; i++){
            prev = prev->next;
            curr = curr->next;
        }

        for(int i=0; i<(right-left); i++){
            ListNode *temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy_head->next;
    }
};