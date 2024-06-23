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
    ListNode* reverse(ListNode *head){
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
    void merge(ListNode *list1, ListNode *list2){
        while (list1){
            ListNode *p = list1->next;
            ListNode *q = list2->next;

            list1->next = list2;
            if (p == nullptr){
                break;
            }
            list2->next = p;

            list1 = p;
            list2 = q;
        }
    }
    void reorderList(ListNode* head) {
        // Break into two halves from between
        // Reverse the next half
        // Rearrange to create a new Linked List
        if (head->next == nullptr){
            return ;
        }
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast != nullptr && fast->next!=nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode *list1 = head;
        ListNode *list2 = reverse(slow);
        
        merge(list1, list2);
    }
};