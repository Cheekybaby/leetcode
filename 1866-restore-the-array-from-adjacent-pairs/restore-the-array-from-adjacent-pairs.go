func dfs(root int, adj map[int][]int, visited map[int]bool, arr *[]int) {
    if _, ok := visited[root]; ok {
        return
    }

    visited[root] = true
    *arr = append(*arr, root)

    for _, dest := range adj[root] {
        if _, ok := visited[dest]; ok {
            continue
        }
        dfs(dest, adj, visited, arr)
    }
}

func restoreArray(adjacentPairs [][]int) []int {
    adj := make(map[int][]int)

    for _, pairs := range adjacentPairs {
        u := pairs[0]
        v := pairs[1]

        adj[u] = append(adj[u], v)
        adj[v] = append(adj[v], u)
    }

    visited := make(map[int]bool)

    root := 0
    for key, value := range adj {
        if len(value) == 1 {
            root = key
            break
        }
    }
    var arr []int
    dfs(root, adj, visited, &arr)

    return arr
}