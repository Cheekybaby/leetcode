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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *first = list1, *second = list1;
        while(a>1){
            first = first->next;
            a--;
        }
        while(b>0){
            second = second->next;
            b--;
        }

        ListNode *last = list2;
        while (last->next){
            last = last->next;
        }
        first->next = list2;
        last->next = second->next;
        delete second;

        return list1;
    }
};