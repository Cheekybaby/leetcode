/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func gcd(a, b int) int {
    for b > 0 {
        tmp := a % b
        a = b
        b = tmp
    }
    return a
}
func insertGreatestCommonDivisors(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }

    prev, curr := head, head.Next
    for curr != nil {
        val := gcd(prev.Val, curr.Val)
        next := curr

        gcdNode := &ListNode{val, next}

        prev.Next = gcdNode

        prev = prev.Next.Next
        curr = curr.Next
    }

    return head
}