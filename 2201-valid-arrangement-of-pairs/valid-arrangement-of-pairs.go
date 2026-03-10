type Degree struct {
    IN  int
    OUT int
}

func dfs(adj map[int][]int, root int) (order []int) {
    var st []int
    st = append(st, root)

    for len(st) > 0 {
        node := st[len(st)-1]

        if len(adj[node]) > 0 {
            v := adj[node][0]
            st = append(st, v)
            adj[node] = adj[node][1:]
        } else {
            order = append(order, node)
            st = st[:len(st)-1]
        }
    }

    return order
}

func makePairs(nums []int) (pairs [][]int) {
    i := len(nums)-1
    for i > 0 {
        pair := []int{nums[i], nums[i-1]}
        pairs = append(pairs, pair)
        i--
    }
    return pairs
}

func validArrangement(pairs [][]int) [][]int {
    adj := map[int][]int{}
    degree := map[int]Degree{}
    for _, pair := range pairs {
        u := pair[0]
        v := pair[1]

        adj[u] = append(adj[u], v)

        du := degree[u]
        du.OUT++
        degree[u] = du

        dv := degree[v]
        dv.IN++
        degree[v] = dv
    }

    var root int = pairs[0][0]
    for key, val := range degree {
        in := val.IN
        out := val.OUT

        if (out - in) == 1 {
            root = key
            break
        }
    }

    order := dfs(adj, root)
    validPairs := makePairs(order)

    return validPairs
}