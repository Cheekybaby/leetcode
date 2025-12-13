/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func bfs(root *TreeNode) int {
    max_sum := math.MinInt
    level, lvl := 1, 1
    var q []*TreeNode
    q = append(q, root)

    for len(q) > 0 {
        n := len(q)
        sum := 0
        for i := 0; i < n; i++ {
            node := q[0]
            q = q[1:]

            sum += node.Val

            if node.Left != nil {
                q = append(q, node.Left)
            }
            if node.Right != nil {
                q = append(q, node.Right)
            }
        }
        if sum > max_sum {
            max_sum = sum
            level = lvl
        }
        lvl++
    }
    return level
}

func maxLevelSum(root *TreeNode) int {
    level := bfs(root)

    return level
}