/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func lengthOfLL(head *ListNode) int {
    length := 0
    dummy := head
    for dummy != nil {
        length++
        dummy = dummy.Next
    }

    return length
}
func rotateRight(head *ListNode, k int) *ListNode {
    length := lengthOfLL(head)

    if length == 0 || length == 1 {
        return head
    }

    k %= length
    if k == 0 {
        return head
    }

    slow, fast := head, head
    for k > 0 {
        fast = fast.Next
        k-=1
    }

    for fast.Next != nil {
        slow = slow.Next
        fast = fast.Next
    }

    newHead := slow.Next
    slow.Next = nil

    fast.Next = head
    return newHead
}