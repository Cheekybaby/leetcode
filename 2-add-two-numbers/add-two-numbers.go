/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	newHead := &ListNode{Val: 0, Next: nil}
	temp := newHead

	carry := 0 

	for l1 != nil || l2 != nil {
		var a, b int
		a = findVal(l1)
        b = findVal(l2)

		sum := a + b + carry
		carry = sum / 10

		temp.Next = &ListNode{Val: sum % 10, Next: nil}
		temp = temp.Next

        l1 = moveForward(l1)
        l2 = moveForward(l2)
	}

	if carry > 0 {
		temp.Next = &ListNode{Val: carry, Next: nil}
	}

	return newHead.Next
}

func findVal(l *ListNode) int {
    if l != nil {
        return l.Val
    }
    return 0
}

func moveForward(l *ListNode) *ListNode {
    if l != nil {
        return l.Next
    }
    return nil
}