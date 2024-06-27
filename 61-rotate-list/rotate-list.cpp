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
    int lengthofLL(ListNode *head){
        int len = 0;
        ListNode *curr = head;
        while (curr){
            len+=1;
            curr = curr->next;
        }

        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        int len = lengthofLL(head);
        k%=len;
        if (k == 0) return head;

        ListNode *slow = head;
        ListNode *fast = head;
        int step = k;
        while (step){
            fast = fast->next;
            step-=1;
        }
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *newhead = slow->next;
        slow->next = nullptr;
        ListNode *temp = newhead;
        while (temp->next){
            temp = temp->next;
        }
        temp->next = head;

        return newhead;
    }
};