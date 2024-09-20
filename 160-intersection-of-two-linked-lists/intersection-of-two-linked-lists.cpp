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
    int lengthOfLL(ListNode *a){
        int len = 0;
        while (a != nullptr){
            len+=1;
            a = a->next;
        }

        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA;
        ListNode *B = headB;
        
        int lenA = lengthOfLL(A);
        int lenB = lengthOfLL(B);

        int steps = abs(lenA - lenB);

        if (lenA > lenB){
            while (steps){
                headA = headA->next;
                steps-=1;
            }
        } else {
            while (steps){
                headB = headB->next;
                steps-=1;
            }
        }

        while (headA != nullptr && headB != nullptr){
            if (headA == headB){
                return headA;
            }

            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};