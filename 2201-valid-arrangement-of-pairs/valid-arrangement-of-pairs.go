func dfs(adj map[int][]int, start int, path *[]int) {
    var st []int
    st = append(st, start)

    for len(st) > 0 {
        node := st[len(st)-1]

        if len(adj[node]) > 0 {
            neighbor := adj[node][len(adj[node])-1]
            st = append(st, neighbor)
            adj[node] = adj[node][:len(adj[node])-1]
        } else {
            *path = append(*path, node)
            st = st[:len(st)-1]
        }
    }
}

func validArrangement(pairs [][]int) [][]int {
    adj := map[int][]int{}
    degree := map[int][2]int{} // [0], [1] = indegree, outdegree
    for _, pair := range pairs {
        u := pair[0]
        v := pair[1]

        adj[u] = append(adj[u], v)

        var temp [2]int
        temp = degree[u]
        temp[1]++
        degree[u] = temp

        temp = degree[v]
        temp[0]++
        degree[v] = temp
    }
    // find the starting node
    var root int = pairs[0][0]
    for key, val := range degree {
        if val[1] - val[0] == 1 {
            root = key
            break
        }
    }

    // hit a DFS over it
    var path []int
    dfs(adj, root, &path)

    // create the final result
    var res [][]int
    for i := len(path)-1; i > 0; i-- {
        pair := []int{path[i], path[i-1]}
        res = append(res, pair)
    }

    return res
}