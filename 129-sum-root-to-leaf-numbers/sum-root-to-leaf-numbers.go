/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func dfs(root *TreeNode, digits []int, nums *[]int) {
    if root.Left == nil && root.Right == nil {
        digits = append(digits, root.Val)

        num := 0

        for i := range digits {
            num = num * 10 + digits[i]
        }

        *nums = append(*nums, num)

        return
    }

    digit := (root.Val)
    digits = append(digits, digit)

    if root.Left != nil {
        dfs(root.Left, digits, nums)
    }
    if root.Right != nil {
        dfs(root.Right, digits, nums)
    }
}

func sumNumbers(root *TreeNode) int {
    var digits []int
    var nums []int

    dfs(root, digits, &nums)

    sum := 0
    for i := range nums {
        sum += nums[i]
    }
    return sum
}