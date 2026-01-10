/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func doubleIt(head *ListNode) *ListNode {
    var st []*ListNode
    curr := head

    for curr != nil {
        st = append(st, curr)
        curr = curr.Next
    }
    carry := 0
    for len(st) > 0 {
        node := st[len(st)-1]
        st = st[:len(st)-1]

        val := node.Val * 2 + carry
        carry = val / 10
        node.Val = val % 10
    }

    if carry > 0 {
        newHead := &ListNode{carry, head}
        return newHead
    }

    return head
}