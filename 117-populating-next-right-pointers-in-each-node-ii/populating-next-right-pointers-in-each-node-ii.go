/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */

func connect(root *Node) *Node {
	if root == nil {
        return root
    }

    var q []*Node
    q = append(q, root)

    for len(q) != 0 {
        n := len(q)
        var level []*Node
        for i := 0; i < n; i++ {
            node := q[0]
            q = q[1:]

            level = append(level, node)

            if node.Left != nil {
                q = append(q, node.Left)
            }
            if node.Right != nil {
                q = append(q, node.Right)
            }
        }

        for i := 0; i < n-1; i++ {
            node := level[i]
            node.Next = level[i+1]
        }
    }

    return root
}