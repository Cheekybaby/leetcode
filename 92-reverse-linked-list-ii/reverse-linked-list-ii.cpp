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
        ListNode *dummy = new ListNode(0, head);

        ListNode *curr = head, *leftNode = dummy;
        int i=0;
        while (i < left-1){
            leftNode = curr;
            curr = curr->next;
            i+=1;
        }

        ListNode *prev = nullptr;
        i = 0;
        while (i < right-left+1){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            i+=1;
        }

        leftNode->next->next = curr;
        leftNode->next = prev;

        return dummy->next;
    }
};