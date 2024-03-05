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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *prev = nullptr;
        ListNode *current = head;
        while (current){
            ListNode *temp = new ListNode(current->val);
            temp->next = prev;
            prev = temp;
            current = current->next;
        }
        ListNode *temp = head;
        while (temp && prev){
            if (prev->val != temp->val){
                return false;
            }
            temp = temp->next;
            prev = prev->next;
        }

        return true;
    }
};