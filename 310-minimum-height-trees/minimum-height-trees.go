func findMinHeightTrees(n int, edges [][]int) []int {
    if n == 1 {
        return []int{0}
    }

    adj := make([][]int, n)

    indegree := make([]int, n)

    for i := range edges {
        u := edges[i][0]
        v := edges[i][1]

        adj[u] = append(adj[u], v)
        adj[v] = append(adj[v], u)

        indegree[u]++
        indegree[v]++
    }

    var q []int
    for i := range indegree {
        if indegree[i] == 1 {
            q = append(q, i)
        }
    }

    remaining := n
    for remaining > 2 {
        size := len(q)
        remaining -= size

        for _ = range size {
            node := q[0]
            q = q[1:]

            for _, v := range adj[node] {
                indegree[v]--

                if indegree[v] == 1 {
                    q = append(q, v)
                }
            }
        }
    }

    var root []int
    for len(q) > 0 {
        root = append(root, q[0])
        q = q[1:]
    }

    return root
}