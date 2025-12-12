func dfs(adj [][]int, source int, destination int, visited []bool) bool {
    if source == destination {
        return true
    }

    visited[source] = true

    for _, v := range adj[source] {
        if !visited[v] && dfs(adj, v, destination, visited) {
            return true
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

    path_exists := dfs(adj, source, destination, visited)

    return path_exists
}