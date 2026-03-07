func topoSort(adj [][]int) (sorted []int) {
    n := len(adj)
    indegree := make([]int, n)
    for _, v := range adj {
        for _, val := range v {
            indegree[val]++
        }
    }
    
    var q []int
    for i, u := range indegree {
        if u == 0 { q = append(q, i) }
    }

    for len(q) > 0 {
        node := q[0]
        q = q[1:]

        sorted = append(sorted, node)

        for _, v := range adj[node] {
            indegree[v]--

            if indegree[v] == 0 { q = append(q, v) }
        }
    }

    return sorted
}

func findOrder(numCourses int, prerequisites [][]int) []int {
    adj := make([][]int, numCourses)
    for _, course := range prerequisites {
        u := course[1]
        v := course[0]

        adj[u] = append(adj[u], v)
    }

    sorted := topoSort(adj)

    if len(sorted) != numCourses { return []int{} }
    return sorted
}