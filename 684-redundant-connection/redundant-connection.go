func isConnected(adj [][]int, root, target int, visited []bool) bool {
    visited[root] = true

    for _, v := range adj[root] {
        if v == target { return true }
        if !visited[v] && isConnected(adj, v, target, visited) { return true }
    }

    return false
}

func findRedundantConnection(edges [][]int) []int {
    n := len(edges) // number of nodes
    adj := make([][]int, n)

    for _, edge := range edges {
        u := edge[0] - 1
        v := edge[1] - 1
        
        visited := make([]bool, n)
        if isConnected(adj, u, v, visited) {
            return edge
        }

        adj[u] = append(adj[u], v)
        adj[v] = append(adj[v], u)
    }

    return []int{}
}