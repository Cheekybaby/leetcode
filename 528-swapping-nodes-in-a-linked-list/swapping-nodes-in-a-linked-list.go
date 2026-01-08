/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapNodes(head *ListNode, k int) *ListNode {
    if head == nil || head.Next == nil { return head }

    first, second, curr := head, head, head
    cnt := 0

    for curr != nil {
        cnt++

        if cnt == k {
            first = curr
        } else if cnt > k {
            second = second.Next
        }

        curr = curr.Next
    }

    first.Val, second.Val = second.Val, first.Val

    return head
}