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
        ListNode *start = list1, *end = list1;
        for (int i=1; i<a; i+=1){
            start = start->next;
        }
        for (int i=1; i<=b+1; i+=1){
            end = end->next;
        }

        start->next = list2;

        ListNode *last = list2;

        while (last->next != nullptr){
            last = last->next;
        }

        last->next = end;

        return list1;
    }
};