/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func inorder(root *TreeNode, insert bool, prefix *[]int) {
    if root == nil {
        return
    }

    inorder(root.Left, insert, prefix)
    if !insert {
        *prefix = append(*prefix, root.Val)
    } else {
        root.Val = (*prefix)[0]
        *prefix = (*prefix)[1:]
    }
    inorder(root.Right, insert, prefix)
}

func bstToGst(root *TreeNode) *TreeNode {
    prefix := []int{}
    inorder(root, false, &prefix)

    for i := len(prefix)-2; i >= 0; i-- {
        prefix[i] += prefix[i+1]
    }
    
    inorder(root, true, &prefix)

    return root
}