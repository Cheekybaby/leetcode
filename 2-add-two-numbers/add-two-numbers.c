/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    struct ListNode *temp = dummy;
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
        int a = (l1 != NULL) ? l1->val : 0;
        int b = (l2 != NULL) ? l2->val : 0;

        int sum = a + b + carry;
        carry = sum / 10;

        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    if (carry == 1) {
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = carry;
        newNode->next = NULL;

        temp->next = newNode;
    }
    struct ListNode *head = dummy->next;
    free(dummy);
    return head;
}