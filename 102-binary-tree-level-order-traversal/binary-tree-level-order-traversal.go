/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
    var traversal [][]int
    if root == nil {
        return traversal
    }
    var q []*TreeNode
    q = append(q, root)

    for len(q) != 0 {
        n := len(q)
        var level []int

        for i := 0; i < n; i++ {
            node := q[0]
            q = q[1:]

            level = append(level, node.Val)

            if node.Left != nil { q = append(q, node.Left) }
            if node.Right != nil { q = append(q, node.Right) }
        }

        traversal = append(traversal, level)
    }

    return traversal
}