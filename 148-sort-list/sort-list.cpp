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
    ListNode *midofLL(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *merge(ListNode *head1, ListNode *head2){
        ListNode *dummy = new ListNode();
        ListNode *ptr = dummy;
        ListNode *left = head1, *right = head2;

        while (left != nullptr && right != nullptr){
            if (left->val < right->val){
                ListNode *temp = left->next;
                ptr->next = left;
                left->next = nullptr;
                left = temp;
            } else {
                ListNode *temp = right->next;
                ptr->next = right;
                right->next = nullptr;
                right = temp;
            }
            ptr = ptr->next;
        }
        if (left == nullptr){
            ptr->next = right;
        } else if (right == nullptr) {
            ptr->next = left;
        }

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr){
            return nullptr;
        }
        if (head->next == nullptr){
            return head;
        }

        ListNode *mid = midofLL(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        head = merge(left, right);

        return head;
    }
};