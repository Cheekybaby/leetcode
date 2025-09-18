func findOrder(n int, pre [][]int) []int {
    adj := make([][]int, n)
    for i := range pre {
        u := pre[i][1]
        v := pre[i][0]

        adj[u] = append(adj[u], v)
    }

    indegree := make([]int, n)
    for i := range adj {
        for _, v := range adj[i] {
            indegree[v]++
        }
    }

    var q []int // queue
    for i, val := range indegree {
        if val == 0 {
            q = append(q, i) // Push
        }
    }
    var top_order []int
    for len(q) > 0 {
        u := q[0] // q.front()
        q = q[1:] // q.pop()

        top_order = append(top_order, u)

        for _, v := range adj[u] {
            indegree[v]--

            if indegree[v] == 0 {
                q = append(q, v)
            }
        }
    }

    if len(top_order) == n {
        return top_order
    }

    return []int{}
}