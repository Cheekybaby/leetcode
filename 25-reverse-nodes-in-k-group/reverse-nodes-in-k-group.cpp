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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = lengthOfLL(head);

        int groups = len / k; // Number of groups of k nodes that needs to be reversed.
        int left = 0;
        while (groups--){
            head = reverseLL(head, left, k);
            left += k;
        }
        
        return head;
    }
private:
    int lengthOfLL(ListNode *head){
        int len = 0;
        ListNode *temp = head;
        while (temp){
            len+=1;
            temp = temp->next;
        }

        return len;
    }
    ListNode* reverseLL(ListNode *head, int left, int k){
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy, *curr = head;

        for (int i=0; i<left; i+=1){
            prev = prev->next;
            curr = curr->next;
        }

        // ListNode *curr = prev->next;

        for (int i=0; i<k-1; i+=1){
            ListNode *temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        head = dummy->next;
        return head;
    }
};