func kahnsAlgorithm(adj [][]int, indegree []int) bool {
    var q []int
    for i, val := range indegree {
        if val == 0 {
            q = append(q, i)
        }
    }

    var sorted []int

    for len(q) > 0 {
        node := q[0]
        q = q[1:]

        sorted = append(sorted, node)

        for _, v := range adj[node] {
            indegree[v]--

            if indegree[v] == 0 {
                q = append(q, v)
            }
        }
    }

    return (len(sorted) == len(adj))
}

func canFinish(numCourses int, prerequisites [][]int) bool {
    adj := make([][]int, numCourses)
    for _, course := range prerequisites {
        u := course[1]
        v := course[0]

        adj[u] = append(adj[u], v)
    }
    indegree := make([]int, numCourses)
    for _, outgoing := range adj {
        for _, v := range outgoing {
            indegree[v]++
        }
    }

    // call kahn's algorithm right here 
    return kahnsAlgorithm(adj, indegree)
}