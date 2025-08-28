/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    newHead := &ListNode{Val: 0, Next: nil}
    temp := newHead

    for l1 != nil || l2 != nil {
        v1 := getVal(l1)
        v2 := getVal(l2)

        if v1 <= v2 {
            temp.Next = l1
            
            if l1 != nil {
                l1 = l1.Next
            }
        } else {
            temp.Next = l2

            if l2 != nil {
                l2 = l2.Next
            }
        }
        temp = temp.Next
    }

    return newHead.Next
}

func getVal(l *ListNode) int {
    if l != nil {
        return l.Val
    }
    return 101
}