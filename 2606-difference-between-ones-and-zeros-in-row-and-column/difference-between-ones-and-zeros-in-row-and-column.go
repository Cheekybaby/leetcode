func onesMinusZeros(grid [][]int) [][]int {
    m, n := len(grid), len(grid[0])
    rows, cols := make([]int, m), make([]int, n)
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == 1 {
                rows[i]++
                cols[j]++
            }
        }
    }
    diff := make([][]int, m)
    for i := range diff {
        diff[i] = make([]int, n)
    }
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            diff[i][j] = rows[i] + cols[j] - (n - rows[i]) - (m - cols[j])
        }
    }

    return diff
}