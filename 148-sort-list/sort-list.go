/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func sortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    var nodes []*ListNode

    dummy := head
    for dummy != nil {
        nodes = append(nodes, dummy)
        dummy = dummy.Next
    }

    sort.Slice(nodes, func (i, j int) bool {
        return nodes[i].Val < nodes[j].Val
    })

    for i := 0; i < len(nodes); i++ {
        if i == len(nodes)-1 {
            nodes[i].Next = nil
            continue
        }
        nodes[i].Next = nodes[i+1]
    }

    return nodes[0]
}