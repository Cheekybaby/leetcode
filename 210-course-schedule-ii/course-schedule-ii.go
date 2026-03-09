func bfs(adj [][]int, indegree []int) (order []int) {
    var q []int
    for i, val := range indegree {
        if val == 0 { q = append(q, i) }
    }

    for len(q) > 0 {
        curr := q[0]
        q = q[1:]

        order = append(order, curr)

        for _, v := range adj[curr] {
            indegree[v]--

            if indegree[v] == 0 { q = append(q, v) }
        }
    }

    return order
}

func findOrder(numCourses int, prerequisites [][]int) []int {
    adj := make([][]int, numCourses)
    indegree := make([]int, numCourses)
    for _, course := range prerequisites {
        u := course[1]
        v := course[0]

        adj[u] = append(adj[u], v)
        indegree[v]++
    }

    order := bfs(adj, indegree)

    if len(order) != numCourses {
        return []int{}
    }
    return order
}