/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrderBottom(root *TreeNode) [][]int {
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

    reverse(traversal)

    return traversal
}
func reverse(nums [][]int) {
    i, j := 0, len(nums)-1

    for i < j {
        nums[i], nums[j] = nums[j], nums[i]
        i++
        j--
    }
}