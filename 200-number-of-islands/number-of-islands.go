var dir = [][]int{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}

func bfs(grid [][]byte, i, j int) {
    grid[i][j] = '0'

    var q [][2]int
    q = append(q, [2]int{i, j})

    for len(q) > 0 {
        curr := q[0]
        q = q [1:]

        r, c := curr[0], curr[1]
        for _, d := range dir {
            dr := r + d[0]
            dc := c + d[1]

            if (dr < 0 || dr >= len(grid)) || (dc < 0 || dc >= len(grid[0])) || (grid[dr][dc] == '0') {
                continue
            }

            grid[dr][dc] = '0'
            q = append(q, [2]int{dr, dc})
        }

    }
}

func numIslands(grid [][]byte) int {
    m, n := len(grid), len(grid[0])
    cnt := 0
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == '1' {
                cnt++
                bfs(grid, i, j)
            }
        }
    }
    return cnt
}