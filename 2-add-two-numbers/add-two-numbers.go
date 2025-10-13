/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    head := &ListNode{Val: 0, Next: nil}
    dummy := head
    carry := 0
    for l1 != nil || l2 != nil {
        v1 := getVal(l1)
        v2 := getVal(l2)

        sum := v1 + v2 + carry
        carry = sum / 10

        newNode := &ListNode{Val: sum%10, Next: nil}
        dummy.Next = newNode
        dummy = newNode

        if l1 != nil {
            l1 = l1.Next
        }
        if l2 != nil {
            l2 = l2.Next
        }
    }

    if carry > 0 {
        newNode := &ListNode{Val: carry, Next: nil}
        dummy.Next = newNode
        dummy = dummy.Next
    }

    return head.Next
}

func getVal(l *ListNode) int {
    if l == nil {
        return 0
    }
    return l.Val
}