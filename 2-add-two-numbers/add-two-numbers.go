/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	// Create new head
	newHead := &ListNode{Val: 0, Next: nil}
	temp := newHead

	carry := 0 // Takes care of the carry along the way

	for l1 != nil || l2 != nil {
		var a, b int
		if l1 != nil {
			a = l1.Val
		} else {
			a = 0
		}

		if l2 != nil {
			b = l2.Val
		} else {
			b = 0
		}

		sum := a + b + carry
		carry = sum / 10
		// Now say temp is looking here
		temp.Next = &ListNode{Val: sum % 10, Next: nil}
		temp = temp.Next

        if l1 != nil {
            l1 = l1.Next
        }
        if l2 != nil {
            l2 = l2.Next
        }
	}

	if carry > 0 {
		temp.Next = &ListNode{Val: carry, Next: nil}
	}

	return newHead.Next
}