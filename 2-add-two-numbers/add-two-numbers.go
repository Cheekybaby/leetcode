/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    head := &ListNode{}
    temp := head
    carry := 0

    for l1 != nil || l2 != nil {
        a, b := 0, 0
        if l1 != nil {
            a = l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            b = l2.Val
            l2 = l2.Next
        }

        value := a + b + carry
        carry = value / 10

        temp.Next = &ListNode{Val:(value%10)}
        temp = temp.Next
    }

    if carry == 1 {
        temp.Next = &ListNode{Val: 1}
        temp = temp.Next
    }

    return head.Next
}