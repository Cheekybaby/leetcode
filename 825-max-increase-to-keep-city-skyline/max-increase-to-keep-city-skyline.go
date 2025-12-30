func maxIncreaseKeepingSkyline(grid [][]int) int {
    m, n := len(grid), len(grid[0])
    row, col := make([]int, m), make([]int, n)

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            val := grid[i][j]
            if val > row[i] { row[i] = val }
            if val > col[j] { col[j] = val }
        }
    }
    ans := 0
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            ans += (min(row[i], col[j]) - grid[i][j])
        }
    }

    return ans
}