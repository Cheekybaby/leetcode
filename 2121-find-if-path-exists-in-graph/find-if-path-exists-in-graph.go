func bfs(adj [][]int, source int, destination int, visited []bool) bool {
    visited[source] = true

    var q []int
    q = append(q, source)

    for len(q) > 0 {
        node := q[0]
        q = q[1:]

        if node == destination {
            return true
        }

        for _, v := range adj[node] {
            if !visited[v] {
                visited[v] = true
                q = append(q, v)
            }
        }
    }

    return false
}

func validPath(n int, edges [][]int, source int, destination int) bool {
    adj := make([][]int, n)
    
    for _, edge := range edges {
        u := edge[0]
        v := edge[1]

        adj[u] = append(adj[u], v)
        adj[v] = append(adj[v], u)
    }
    visited := make([]bool, n)
    path_exists := bfs(adj, source, destination, visited)

    return path_exists
}