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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;


        ListNode *newHead = head->next;
        ListNode *prev = nullptr;

        while (head && head->next){
            ListNode *nxtpr = head->next->next;
            ListNode *other = head->next;

            if (prev){
                prev->next = other;
            }

            other->next = head;
            head->next = nxtpr;

            prev = head;
            head = nxtpr;
        }

        return newHead;
    }
};