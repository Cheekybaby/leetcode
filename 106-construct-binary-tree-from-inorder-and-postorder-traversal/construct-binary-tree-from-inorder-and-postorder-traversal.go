/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func builder(inorder []int, inst, inend int, postorder []int, pst, pend int, idxmp map[int]int) *TreeNode {
    if inst > inend || pst > pend {
        return nil
    }

    root := &TreeNode{Val: postorder[pend]}
    inroot := idxmp[root.Val]
    left := inroot - inst

    root.Left = builder(inorder, inst, inroot-1, postorder, pst, pst+left-1, idxmp)
    root.Right = builder(inorder, inroot+1, inend, postorder, pst+left, pend-1, idxmp)

    return root
}

func buildTree(inorder []int, postorder []int) *TreeNode {
    idxmp := make(map[int]int)
    for i := range inorder {
        idxmp[inorder[i]] = i
    }

    return builder(inorder, 0, len(inorder)-1, postorder, 0, len(postorder)-1, idxmp)
}