/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func recoverTree(root *TreeNode)  {
    var first, prev, second *TreeNode

    var dfs func(node *TreeNode)
    dfs = func(node *TreeNode) {
        if node == nil {
            return
        }

        dfs(node.Left)
        if prev != nil {
            if first == nil && prev.Val >= node.Val { first = prev }
            if first != nil && prev.Val >= node.Val { second = node }
        }

        prev = node
        dfs(node.Right)
    }

    dfs(root)

    first.Val, second.Val = second.Val, first.Val
}