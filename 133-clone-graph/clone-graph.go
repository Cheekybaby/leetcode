/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */

func cloneGraph(node *Node) *Node {
    if node == nil { return node }

    pair := make(map[*Node]*Node)

    var q []*Node
    q = append(q, node)
    for len(q) > 0 {
        curr := q[0]
        q = q[1:]

        newNode := &Node{}
        newNode.Val = curr.Val
        newNode.Neighbors = []*Node{}

        pair[curr] = newNode

        for _, n := range curr.Neighbors {
            if _, ok := pair[n]; ok { continue }
            q = append(q, n)
        }
    }

    for key, val := range pair {
        newNode := val
        var neighbors []*Node
        for _, v := range key.Neighbors {
            neighbors = append(neighbors, pair[v])
        }
        newNode.Neighbors = neighbors
    }

    return pair[node]
}