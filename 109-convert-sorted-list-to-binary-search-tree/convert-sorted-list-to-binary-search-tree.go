/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedListToBST(head *ListNode) *TreeNode {
    if head == nil {
        return nil
    }
    if head.Next == nil {
        return &TreeNode{head.Val, nil, nil}
    }

    prev, slow, fast := head, head.Next, head.Next.Next

    for fast != nil && fast.Next != nil {
        prev = slow
        slow = slow.Next
        fast = fast.Next.Next
    }

    prev.Next = nil
    root := TreeNode{slow.Val, nil, nil}

    root.Left = sortedListToBST(head)
    root.Right = sortedListToBST(slow.Next)

    return &root
}