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
    int lenOfLL(ListNode *head){
        int len = 0;
        ListNode* temp = head;
        while (temp){
            len += 1;
            temp = temp->next;
        }

        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        int len = lenOfLL(head);

        k %= len;
        if (k == 0) return head;
        ListNode *slow = head, *fast = head;

        while (k--){
            fast = fast->next;
        }

        while (fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *temp = slow->next;
        slow->next = nullptr;
        fast = temp;

        while (fast->next != nullptr){
            fast = fast->next;
        }

        fast->next = head;


        return temp;
    }
};