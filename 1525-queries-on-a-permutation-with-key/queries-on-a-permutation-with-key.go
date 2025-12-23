func prefixSum(fent []int, idx int) int {
    sum := 0
    for idx > 0 {
        sum += fent[idx]
        idx -= (idx & - idx)
    }
    return sum
}

func updateBIT(fent []int, idx int, val int){
    for idx <= len(fent) {
        fent[idx] += val
        idx += (idx & -idx)
    }
}

func processQueries(queries []int, m int) []int {
    ans := make([]int, len(queries))
    fent := make([]int, 2*m+1)
    pos := make(map[int]int, m)
    for v := 1; v <= m; v++ {
        idx := v + m
        pos[v] = idx
        updateBIT(fent, idx, 1)
    }
    next := m
    for i, v := range queries {
        currIdx := pos[v]
        ans[i] = prefixSum(fent, currIdx - 1)
        updateBIT(fent, currIdx, -1)
        pos[v] = next
        updateBIT(fent, next, 1)
        next--
    }

    return ans
}