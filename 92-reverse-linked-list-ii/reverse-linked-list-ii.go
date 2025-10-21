/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, left int, right int) *ListNode {
    if head.Next == nil || left == right {
        return head
    }

    prev, st, end := &ListNode{Val: 0, Next:head}, head, head

    for i := left; i > 1; i-- {
        prev = st
        st = st.Next
    }

    for i := right; i > 1; i-- {
        end = end.Next
        right--
    }

    // fmt.Println(prev, st, end)

    tmp := st.Next
    st.Next = end.Next
    prev.Next = end
    prev = st
    st = tmp

    for prev != end {
        tmp = st.Next
        st.Next = prev
        prev = st
        st = tmp
    }

    if left == 1 {
        return end
    }
    
    return head
}