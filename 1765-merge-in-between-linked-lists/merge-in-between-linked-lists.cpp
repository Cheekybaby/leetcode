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
        a-=1;
        b+=1;

        while (a||b){
            if (a>0){
                a-=1;
                start = start->next;
            }
            if (b>0){
                b-=1;
                end = end->next;
            }
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