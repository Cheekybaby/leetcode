/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nodesBetweenCriticalPoints(head *ListNode) []int {
    if head == nil || head.Next == nil || head.Next.Next == nil {
        return []int{-1,-1}
    }

    i := 2
    var pos []int
    prev, curr := head, head.Next
    for curr.Next != nil {
        nxt := curr.Next

        // check for local maxima or local minima (critical point)
        if curr.Val > prev.Val && curr.Val > nxt.Val {
            // local maxima (critical point)
            pos = append(pos, i)
        } else if curr.Val < prev.Val && curr.Val < nxt.Val {
            // local minima (critical point)
            pos = append(pos, i)
        }

        prev = curr
        curr = curr.Next
        i++
    }

    if len(pos) < 2 {
        return []int{-1,-1}
    }

    max_dist, min_dist := 0, math.MaxInt
    for i := 0; i < len(pos)-1; i++ {
        diff := pos[i+1] - pos[i]

        min_dist = min(min_dist, diff)
    }
    max_dist = pos[len(pos)-1] - pos[0]
    return []int{min_dist, max_dist}
}