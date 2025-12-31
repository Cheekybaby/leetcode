/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func dfs(root *TreeNode) int {
    if root == nil {
        return 0
    }

    left := dfs(root.Left)
    right := dfs(root.Right)
    
    if left == 0 {
        root.Left = nil
    }
    if right == 0 {
        root.Right = nil
    }

    return root.Val + left + right
}

func pruneTree(root *TreeNode) *TreeNode {
    sum := dfs(root)

    if sum == 0 {
        return nil
    }
    return root
}