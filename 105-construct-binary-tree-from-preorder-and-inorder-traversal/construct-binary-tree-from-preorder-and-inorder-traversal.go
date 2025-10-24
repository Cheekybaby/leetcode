/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func builder(preorder []int, pst, pend int, inorder []int, inst, inend int, idxmp map[int]int) *TreeNode {
    if pst > pend || inst > inend {
        return nil
    }

    root := &TreeNode{Val: preorder[pst]}
    inroot := idxmp[root.Val]
    left := inroot - inst

    root.Left = builder(preorder, pst+1, pst+left, inorder, inst, inroot-1,idxmp)
    root.Right = builder(preorder, pst+left+1, pend, inorder, inroot+1, inend, idxmp)

    return root
}

func buildTree(preorder []int, inorder []int) *TreeNode {
    idxmp := make(map[int]int)

    for i := 0; i < len(inorder); i++ {
        idxmp[inorder[i]] = i
    }

    return builder(preorder, 0, len(preorder)-1, inorder, 0, len(inorder)-1, idxmp)
}