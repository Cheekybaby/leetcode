func dfs(adj [][]int, root int, visited []bool) {
    visited[root] = true

    for i, v := range adj[root] {
        if v == 1 && !visited[i] {
            dfs(adj, i, visited)
        }
    }
}

func findCircleNum(isConnected [][]int) int {
    // we are given adjacency matrix
    n := len(isConnected)
    visited := make([]bool, n)

    var province int
    for i := 0; i < n; i++ {
        if !visited[i] {
            dfs(isConnected, i, visited)
            province++
        }
    }

    return province
}