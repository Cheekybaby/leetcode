/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    curr := head
    set := make(map[int]int)
    for curr != nil {
        set[curr.Val] += 1
        curr = curr.Next
    }

    curr = head
    prev := &ListNode{Val: 0, Next: nil}
    newHead := prev
    
    for curr != nil {
        value, ok := set[curr.Val]

        if !ok {
            return head
        }

        if value == 1 {
            prev.Next = curr
            prev = curr
        }

        curr = curr.Next
    }

    prev.Next = curr

    return newHead.Next
}