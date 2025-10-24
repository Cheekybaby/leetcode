/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func flatten(root *TreeNode)  {
    if root == nil {
        return 
    }
    var st []*TreeNode
    st = append(st, root)

    for len(st) != 0 {
        node := st[len(st)-1]
        st = st[:len(st)-1]

        if node.Right != nil {
            st = append(st, node.Right)
        }
        if node.Left != nil {
            st = append(st, node.Left)
        }

        if len(st) != 0 {
            node.Right = st[len(st)-1]
        }
        node.Left = nil
    }
}