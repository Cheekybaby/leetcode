/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */

func cloneGraph(node *Node) *Node {
    if node == nil {
        return node
    }

    mapping := make(map[*Node]*Node)

    root := &Node{node.Val, []*Node{}}
    mapping[node] = root

    var q []*Node
    q = append(q, node)

    for len(q) != 0 {
        curr := q[0]
        q = q[1:]

        for _, adj := range curr.Neighbors {
            if _, ok := mapping[adj]; !ok {
                mapping[adj] = &Node{adj.Val, []*Node{}}
                q = append(q, adj)
            }

            mapping[curr].Neighbors = append(mapping[curr].Neighbors, mapping[adj])
        }
    }

    return mapping[node]
}