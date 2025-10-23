/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func dfs(root *TreeNode, low, high int) bool {
    if root == nil {
        return true
    }

    if low < root.Val && root.Val < high {
        l := dfs(root.Left, low, root.Val)
        r := dfs(root.Right, root.Val, high)

        return (l && r)
    } else {
        return false
    }
}
func isValidBST(root *TreeNode) bool {
    return dfs(root, math.MinInt, math.MaxInt)
}