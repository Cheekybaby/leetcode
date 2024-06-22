/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        int lenA = 0, lenB = 0;

        while (A){
            lenA+=1;
            A = A->next;
        }
        while (B){
            lenB+=1;
            B = B->next;
        }

        A = headA;
        B = headB;

        if (lenA > lenB){
            int steps = lenA - lenB;
            while (steps){
                A = A->next;
                steps-=1;
            }
        } else {
            int steps = lenB - lenA;
            while (steps){
                B = B->next;
                steps-=1;
            }
        }

        while (A!=nullptr && B!=nullptr){
            if (A == B){
                return A;
            }
            A = A->next;
            B = B->next;
        }

        return A;
    }
};