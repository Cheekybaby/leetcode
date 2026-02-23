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
        x := getVal(l1)
        y := getVal(l2)

        node := &ListNode{}

        sum := x + y + carry
        carry = sum / 10

        node.Val = sum % 10
        temp.Next = node

        temp = temp.Next
        if l1 != nil { l1 = l1.Next }
        if l2 != nil { l2 = l2.Next }
    }

    if carry > 0 {
        node := &ListNode{carry, nil}
        temp.Next = node
    }

    return head.Next
}

func getVal(l *ListNode) int {
    if l != nil {
        return l.Val
    }
    return 0
}