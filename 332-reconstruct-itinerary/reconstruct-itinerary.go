func dfs(adj map[string][]string, root string) (order []string) {
    var st []string
    st = append(st, root)

    for len(st) > 0 {
        node := st[len(st)-1]

        if len(adj[node]) > 0 {
            // still got places to go
            to := adj[node][0]
            adj[node] = adj[node][1:]
            st = append(st, to)
        } else {
            order = append(order, node)
            st = st[:len(st)-1]
        }
    }

    return order
}
func findItinerary(tickets [][]string) []string {
    adj := map[string][]string{}
    indegree, outdegree := map[string]int{}, map[string]int{}
    for _, ticket := range tickets {
        from := ticket[0]
        to := ticket[1]

        adj[from] = append(adj[from], to)

        indegree[to]++
        outdegree[from]++
    }

    for _, val := range adj {
        sort.Strings(val)
    }
    var root string = "JFK"
    order := dfs(adj, root)

    reverse(order)

    return order
}

func reverse(strs []string) {
    i, j := 0, len(strs)-1
    for i < j {
        strs[i], strs[j] = strs[j], strs[i]
        i++
        j--
    }
}