type Frame struct {
    Node    int
    Idx     int
}

func dfs(adj [][]int, root int, visited, inRecursion []bool) bool {
    st := []Frame{{Node : root, Idx : 0}}

    visited[root] = true
    inRecursion[root] = true

    for len(st) > 0 {
        top := &st[len(st)-1]
        currNode := top.Node
        currIdx := top.Idx

        if currIdx == len(adj[currNode]) {
            inRecursion[currNode] = false
            st = st[:len(st)-1]

            continue
        }

        v := adj[currNode][currIdx]
        top.Idx++

        if inRecursion[v] {
            return true
        }

        if !visited[v] {
            visited[v] = true
            inRecursion[v] = true
            st = append(st, Frame{Node: v, Idx : 0})
        }
    }

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