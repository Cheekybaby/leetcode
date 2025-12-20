/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func reverse(node *ListNode) *ListNode {
    var prev *ListNode = nil
    curr := node
    for curr != nil {
        temp := curr.Next
        curr.Next = prev
        prev = curr
        curr = temp
    }

    return prev
}
func pairSum(head *ListNode) int {
    slow, fast := head, head
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }
    left, right := head, reverse(slow)
    max_pair := 0
    for right != nil {
        pair := left.Val + right.Val
        max_pair = max(max_pair, pair)
        
        left = left.Next
        right = right.Next
    }

    return max_pair
}