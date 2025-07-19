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
    ListNode* reverseLL(ListNode *head){
        ListNode *temp = head;
        ListNode *prev = nullptr;
        while (temp){
            ListNode *next_node = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next_node;
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
public:
    void reorderList(ListNode* head) {
        if (head->next == nullptr) return ;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = nullptr;
        ListNode *list1 = head;
        ListNode *list2 = reverseLL(slow);
        merge(list1, list2);
    }
};