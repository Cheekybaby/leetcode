func findMinHeightTrees(n int, edges [][]int) []int {
    if n == 1 { return []int{0} }
    adj := make([][]int, n)
    degree := make([]int, n)

    for _, edge := range edges {
        u := edge[0]
        v := edge[1]

        adj[u] = append(adj[u], v)
        adj[v] = append(adj[v], u)

        degree[u]++
        degree[v]++
    }

    var leaves []int
    for i, val := range degree {
        if val == 1 { leaves = append(leaves, i) }
    }

    for n > 2 {
        n -= len(leaves)
        var newLeaves []int

        for _, leaf := range leaves {
            for _, nei := range adj[leaf] {
                degree[nei]--

                if degree[nei] == 1 { newLeaves = append(newLeaves, nei) }
            }
        }
        leaves = newLeaves
    }

    return leaves
}