/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func reverseLL(head *ListNode) *ListNode {
    var prev *ListNode = nil
    curr := head

    for curr != nil {
        temp := curr.Next
        curr.Next = prev
        prev = curr
        curr = temp
    }

    return prev
}

func doubleIt(head *ListNode) *ListNode {
    revHead := reverseLL(head)

    curr := revHead
    carry := 0
    for curr != nil {
        val := curr.Val * 2 + carry

        carry = val / 10
        curr.Val = val % 10

        if curr.Next == nil && carry > 0 {
            newNode := &ListNode{carry, nil}
            carry = 0
            curr.Next = newNode
            curr = curr.Next
        }

        curr = curr.Next
    }

    newHead := reverseLL(revHead)

    return newHead
}