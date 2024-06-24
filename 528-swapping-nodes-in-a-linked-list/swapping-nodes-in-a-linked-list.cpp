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
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode *curr = head, *first = head, *second = head;
        int a = 0;
        while (curr){
            a+=1;
            if (a == k){
                first = curr;
            }
            if (a >= k+1){
                second = second->next;
            }
            curr = curr->next;
        }

        int temp = first->val;
        first->val = second->val;
        second->val = temp;

        return head;
    }
};