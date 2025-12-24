/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func modifiedList(nums []int, head *ListNode) *ListNode {
    set := map[int]bool{}
    for _, num := range nums {
        set[num] = true
    }

    prev := &ListNode{0, head}
    newHead := prev
    curr := head
    for curr != nil {
        _, ok := set[curr.Val]
        if ok {
            temp := curr.Next // the next node -> curr will move here
            prev.Next = temp // we update the next node for the prev node
            curr = temp // curr is shifted to the desired node
        } else {
            prev = curr
            curr = curr.Next
        }
    }
    return newHead.Next
}