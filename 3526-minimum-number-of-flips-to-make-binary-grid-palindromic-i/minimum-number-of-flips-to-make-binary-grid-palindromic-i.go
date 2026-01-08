func minFlips(grid [][]int) int {
    m, n := len(grid), len(grid[0])

    row_flips := 0
    for i := 0; i < m; i++ {
        flip := 0
        l, r := 0, n-1
        for l < r {
            if grid[i][l] != grid[i][r] {
                flip++
            }
            l++
            r--
        }
        row_flips += flip
    }
    
    col_flips := 0
    for i := 0; i < n; i++ {
        flip := 0
        l, r := 0, m-1
        for l < r {
            if grid[l][i] != grid[r][i] {
                flip++
            }
            l++
            r--
        }
        col_flips += flip
    }

    return min(row_flips, col_flips)
}