type Edge struct {
    To string
    Cost float64
}

func dfs(adj map[string][]Edge, from, to string, visited map[string]bool) (float64) {
    if from == to { return 1.0 }
    visited[from] = true

    for _, v := range adj[from] {
        if !visited[v.To] {
            res := dfs(adj, v.To, to, visited)
            if res != -1 {
                return v.Cost * res
            }
        }
    }

    return -1.0
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
    adj := map[string][]Edge{}
    for i, eq := range equations {
        u := eq[0]
        v := eq[1]

        cost := values[i]

        adj[u] = append(adj[u], Edge{v, cost})
        adj[v] = append(adj[v], Edge{u, 1 / cost})
    }

    fmt.Println(adj)

    var ans []float64
    for _, q := range queries {
        from := q[0]
        to := q[1]

        if _, ok := adj[from]; !ok { 
            ans = append(ans, float64(-1))
            continue
        }
        if _, ok := adj[to]; !ok {
            ans = append(ans, float64(-1))
            continue
        }

        visited := map[string]bool{}
        cost := dfs(adj, from, to, visited)
        ans = append(ans, cost)
    }

    return ans
}