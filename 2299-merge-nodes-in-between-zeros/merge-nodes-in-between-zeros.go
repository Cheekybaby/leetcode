/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeNodes(head *ListNode) *ListNode {
    newHead := &ListNode{0, head.Next}
    dummy := newHead
    curr := head.Next
    sum := 0
    for curr != nil {
        if curr.Val != 0 {
            sum += curr.Val
            curr = curr.Next
            continue
        }
        newNode := &ListNode{sum, nil}
        dummy.Next = newNode
        dummy = dummy.Next
        sum = 0
        curr = curr.Next
    }

    return newHead.Next
}