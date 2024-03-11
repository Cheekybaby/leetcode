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
private:
    ListNode* reverse(ListNode* pt){
        int size = 0;
        ListNode *temp = pt;
        while (temp){
            size+=1;
            temp = temp->next;
        }
        ListNode *prev = nullptr, *curr = pt;
        while (curr){
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }    
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverse(slow);
        int maxSum = 0;
        while(slow && head){
            int sum = head->val + slow->val;
            maxSum = max(sum, maxSum);
            head = head->next;
            slow = slow->next;
        }

        return maxSum;
    }
};