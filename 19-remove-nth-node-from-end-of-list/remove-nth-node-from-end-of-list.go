/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    if head == nil {
        return head
    }

    slow, fast := head, head

    for _ = range n {
        fast = fast.Next
    }

    if fast == nil {
        return head.Next
    }

    for fast.Next != nil {
        slow = slow.Next
        fast = fast.Next
    }

    slow.Next = slow.Next.Next

    // fmt.Println(slow, fast)

    return head
}