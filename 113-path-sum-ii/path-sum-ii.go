/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func dfs(root *TreeNode, targetSum int, sum int, path []int, paths *[][]int) {
    if root.Left == nil && root.Right == nil {
        sum += root.Val
        
        path = append(path, root.Val)

        if sum == targetSum {
            temp := make([]int, len(path))
            copy(temp, path)
            *paths = append(*paths, temp)
        }

        return
    }

    sum += root.Val
    
    path = append(path, root.Val)
    
    if root.Left != nil {
        dfs(root.Left, targetSum, sum, path, paths)
    }
    if root.Right != nil {
        dfs(root.Right, targetSum, sum, path, paths)
    }
}

func pathSum(root *TreeNode, targetSum int) [][]int {
    if root == nil {
        return [][]int{}
    }
    var path []int
    var paths [][]int

    dfs(root, targetSum, 0, path, &paths)

    return paths
}