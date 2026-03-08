func dfs(adj map[string][]string, root string, path *[]string) {
    var st []string
    st = append(st, root)

    for len(st) > 0 {
        node := st[len(st)-1]

        if len(adj[node]) > 0 {
            // we need this to be in the stack right now
            dest := adj[node][0]
            st = append(st, dest)
            adj[node] = adj[node][1:]
        } else {
            // we can push it in the path
            *path = append(*path, node)
            st = st[:len(st)-1]
        }
    }
}

func findItinerary(tickets [][]string) []string {
    adj := map[string][]string{}
    for _, ticket := range tickets {
        from := ticket[0]
        to := ticket[1]

        adj[from] = append(adj[from], to)
    }

    for _, dest := range adj {
        sort.Strings(dest)
    }

    fmt.Println(adj)

    var start string = "JFK"
    var path []string
    dfs(adj, start, &path)

    reverse(path)

    return path
}

func reverse(path []string) {
    i, j := 0, len(path)-1
    for i < j {
        path[i], path[j] = path[j], path[i]
        i++
        j--
    }
}