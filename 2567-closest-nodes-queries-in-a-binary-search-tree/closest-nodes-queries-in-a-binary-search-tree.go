/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func inorder(root *TreeNode, traverse *[]int) {
    if root == nil {
        return
    }

    if root.Left != nil {
        inorder(root.Left, traverse)
    }
    *traverse = append(*traverse, root.Val)
    if root.Right != nil {
        inorder(root.Right, traverse)
    }
}

func closestNodes(root *TreeNode, queries []int) [][]int {
    var traverse []int
    inorder(root, &traverse)
    
    var ans [][]int

    fmt.Println(traverse)

    for i := range queries {
        mini := lower(queries[i], traverse)
        maxi := upper(queries[i], traverse)

        ans = append(ans, []int{maxi, mini})
    }

    return ans
}

func lower(x int, nums []int) int {
    left, right := 0, len(nums)-1
    for left <= right {
        mid := left + (right - left) / 2

        if nums[mid] == x {
            return x
        } else if nums[mid] > x {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }

    if left > len(nums)-1 {
        return -1
    }
    return nums[left]
}
func upper(x int, nums []int) int {
    left, right := 0, len(nums)-1
    for left <= right {
        mid := left + (right - left)/2

        if nums[mid] == x {
            return x
        } else if nums[mid] > x {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }

    if right < 0 {
        return -1
    }

    return nums[right]
}