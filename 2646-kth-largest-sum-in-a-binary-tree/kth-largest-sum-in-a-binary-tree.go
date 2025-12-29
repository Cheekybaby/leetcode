/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthLargestLevelSum(root *TreeNode, k int) int64 {
    level_sum := []int64{}

    var q []*TreeNode
    q = append(q, root)

    for len(q) > 0 {
        n := len(q)
        var sum int64
        for _ = range n {
            node := q[0]
            q = q[1:]

            sum += int64(node.Val)

            if node.Left != nil { q = append(q, node.Left) }
            if node.Right != nil { q = append(q, node.Right) }
        }
        level_sum = append(level_sum, sum)
    }

    if k > len(level_sum) {
        return -1
    }

    sort.Slice(level_sum, func (i, j int) bool {
        return level_sum[i] > level_sum[j]
    })

    return level_sum[k-1]
}