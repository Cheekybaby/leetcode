/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deepestLeavesSum(root *TreeNode) int {
    res := 0
    var q []*TreeNode
    q = append(q, root)

    for len(q) > 0 {
        n := len(q)
        sum := 0
        for _ = range n {
            node := q[0]
            q = q[1:]

            sum += node.Val

            if node.Left != nil { q = append(q, node.Left) }
            if node.Right != nil { q = append(q, node.Right) }
        }
        res = sum
    }

    return res
}