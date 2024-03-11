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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
        while (temp){
            len+=1;
            temp = temp->next;
        }
        if (len<n){
            return head;
        }
        if (len == n){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        int step = len-n;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (step--){
            temp = curr;
            curr = curr->next;
            prev = temp;
        }
        prev->next = curr->next;
        delete curr;
        return head;
    }
};