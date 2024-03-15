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
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        ListNode* length = head;
        while (length){
            len+=1;
            length = length->next;
        }

        int n = len - k + 1;
        ListNode *first = nullptr, *last = nullptr;
        ListNode *temp = head;
        int i = 0;
        while (temp){
            i+=1;
            if (i == k){
                first = temp;
            }
            if (i == n){
                last = temp;
            }
            if (first!=nullptr && last!=nullptr){
                break;
            }
            temp = temp->next;
        }

        swap(first->val, last->val);

        return head;
    }
};