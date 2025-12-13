/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func dfs(root *TreeNode, list *[]int) {
    if root == nil {
        return 
    }

    dfs(root.Left, list)
    *list = append(*list, root.Val)
    dfs(root.Right, list)
}

func merge(list1, list2 []int) []int {
    m, n := len(list1), len(list2)

    all_ele := make([]int, (m + n))

    i, j, k := 0, 0, 0
    for i < m || j < n {
        v1, v2 := math.MaxInt, math.MaxInt
        if i < m {
            v1 = list1[i]
        }
        if j < n {
            v2 = list2[j]
        }

        if v1 <= v2 {
            all_ele[k] = v1
            i++
        } else {
            all_ele[k] = v2
            j++
        }
        k++
    }
    return all_ele
}

func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
    var list1, list2 []int
    dfs(root1, &list1)
    dfs(root2, &list2)

    allElements := merge(list1, list2)

    return allElements
}