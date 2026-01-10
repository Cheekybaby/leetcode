func canReach(arr []int, start int) bool {
    n := len(arr)

    adj := map[int][]int{}

    for i, num := range arr {
        forward, backward := i + num, i - num

        if forward >= n {
            forward = -1
        }
        if backward < 0 {
            backward = -1
        }

        if forward != -1 {
            adj[i] = append(adj[i], forward)
        }
        if backward != -1 {
            adj[i] = append(adj[i], backward)
        }
    }

    var q []int
    q = append(q, start)
    visited := make([]bool, n)
    for len(q) > 0 {
        size := len(q)
        
        for _ = range size {
            node := q[0]
            q = q[1:]

            if arr[node] == 0 {
                return true
            }

            visited[node] = true

            for _, v := range adj[node] {
                if !visited[v] {
                    q = append(q, v)
                }
            }
        }
    }

    return false
}