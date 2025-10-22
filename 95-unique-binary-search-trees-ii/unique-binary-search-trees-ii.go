/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func constructBST(start, end int) []*TreeNode {
    var BSTs []*TreeNode

    if start > end {
        return []*TreeNode{nil}
    }

    for i := start; i <= end; i++ {
        leftSubtree := constructBST(start, i-1)
        rightSubtree := constructBST(i+1, end)

        for _, left := range leftSubtree {
            for _, right := range rightSubtree {
                root := &TreeNode{Val: i, Left: left, Right: right}

                BSTs = append(BSTs, root)
            }
        }
    }

    return BSTs
}
func generateTrees(n int) []*TreeNode {
    if n == 0 {
        return []*TreeNode{}
    }


    return constructBST(1, n)
}