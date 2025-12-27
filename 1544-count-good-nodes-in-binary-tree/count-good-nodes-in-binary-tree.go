/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func dfs(root *TreeNode, maxi int) int {
    if root == nil {
        return 0
    }

    cnt := 0
    if root.Val >= maxi {
        maxi = root.Val
        cnt += 1
    }

    left := dfs(root.Left, maxi)
    right := dfs(root.Right, maxi)

    return cnt + left + right
}

func goodNodes(root *TreeNode) int {
    maxi := root.Val
    cnt := dfs(root, maxi)

    return cnt
}