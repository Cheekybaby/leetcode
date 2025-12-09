func findOrder(n int, pre [][]int) []int {
    adj := make([][]int, n)
    for i := range pre {
        u := pre[i][1]
        v := pre[i][0]

        adj[u] = append(adj[u], v)
    }

    indegree := make([]int, n)

    for i := range adj {
        for j := range adj[i] {
            indegree[adj[i][j]]++
        }
    }

    var q []int

    for i := range indegree {
        if indegree[i] == 0 {
            q = append(q, i)
        }
    }

    var order []int
    for len(q) > 0 {
        node := q[0]
        q = q[1:]

        order = append(order, node)

        for _, v := range adj[node] {
            indegree[v]--

            if indegree[v] == 0 {
                q = append(q, v)
            }
        }
    }

    if len(order) != n {
        return []int{}
    }

    return order
}