func dfs(adj [][]int, root int, visited, inRecursion []bool) bool {
    visited[root] = true
    inRecursion[root] = true

    for _, v := range adj[root] {
        if inRecursion[v] {
            return true
        }
        if !visited[v] && dfs(adj, v, visited, inRecursion) {
            return true
        }
    }

    inRecursion[root] = false
    return false
}

func canFinish(n int, pre [][]int) bool {
    adj := make([][]int, n)
    for i := range pre {
        u := pre[i][1]
        v := pre[i][0]

        adj[u] = append(adj[u], v)
    }

    visited, inRecursion := make([]bool, n), make([]bool, n)
    for i := range n {
        if !visited[i] && dfs(adj, i, visited, inRecursion) {
            return false
        }
    }

    return true
}