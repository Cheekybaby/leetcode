/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow){
                break;
            }
        }
        if (fast == nullptr || fast->next == nullptr){
            return false;
        }
        slow = head;

        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        if (slow == fast){
            return true;
        }

        return false;
    }
};