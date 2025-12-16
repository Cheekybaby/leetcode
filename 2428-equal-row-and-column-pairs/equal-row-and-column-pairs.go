func equalPairs(grid [][]int) int {
    cnt := 0
    n := len(grid)
    for i := 0; i < n; i++ {
        row := grid[i]
        for c := 0; c < n; c++ {
            same := 0
            for r := 0; r < n; r++ {
                if grid[r][c] == row[r] {
                    same++
                }
            }
            if same == n {
                cnt++
            }
        }
    }
    return cnt
}