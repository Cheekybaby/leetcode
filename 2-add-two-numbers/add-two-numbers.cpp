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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *temp = head;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr){
            int a = (l1!=nullptr) ? l1->val : 0;
            int b = (l2!=nullptr) ? l2->val : 0;

            int sum = a + b + carry;
            carry = sum/10;

            temp->next = new ListNode(sum%10);

            if (l1!=nullptr) l1 = l1->next;
            if (l2!=nullptr) l2 = l2->next;

            temp = temp->next;
        }

        if (carry > 0){
            temp->next = new ListNode(carry);
        }

        return head->next;
    }
};