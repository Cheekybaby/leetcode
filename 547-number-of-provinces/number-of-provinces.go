func dfs(adj [][]int, root int, visited []bool) {
    visited[root] = true

    for v, isConnected := range adj[root] {
        if isConnected == 1 && !visited[v] {
            dfs(adj, v, visited)
        }
    }
}

func findCircleNum(isConnected [][]int) int {
    n := len(isConnected)

    visited := make([]bool, n)
    var provinces int
    for i := 0; i < n; i++ {
        if (!visited[i]) {
            dfs(isConnected, i, visited)
            provinces++
        }
    }

    return provinces
}