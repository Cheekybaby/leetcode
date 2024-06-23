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
    ListNode *reverse(ListNode *head){
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *rev = reverse(slow);
        int ans = INT_MIN;
        while (rev){
            int sum = rev->val + head->val;
            ans = max(ans, sum);
            rev = rev->next;
            head = head->next;
        }

        return ans;
    }
};