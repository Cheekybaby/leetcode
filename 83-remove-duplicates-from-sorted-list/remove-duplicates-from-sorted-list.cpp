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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = head, *curr = head;
        while (curr){
            while (curr!=nullptr && curr->val == prev->val){
                curr = curr->next;
            }

            prev->next = curr;
            prev = prev->next;
        }

        return head;
    }
};