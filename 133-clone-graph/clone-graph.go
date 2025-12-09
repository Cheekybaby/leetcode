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

    mapping := map[*Node]*Node{}

    var q []*Node
    q = append(q, node)

    for len(q) > 0 {
        curr := q[0]
        q = q[1:]

        newCurr := &Node{Val : curr.Val, Neighbors : []*Node{}}
        mapping[curr] = newCurr

        for _, v := range curr.Neighbors {
            if _, ok := mapping[v]; !ok {
                q = append(q, v)
            }
        }
    }

    for key, val := range mapping {
        neigh := make([]*Node, len(key.Neighbors))

        for i, v := range key.Neighbors {
            neigh[i] = mapping[v]
        }

        val.Neighbors = neigh
    }


    return mapping[node]
}