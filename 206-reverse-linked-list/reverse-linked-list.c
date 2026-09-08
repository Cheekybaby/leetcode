/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseLL(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* n = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;

    return n;
}

struct ListNode* reverseList(struct ListNode* head) {
    return reverseLL(head);
}