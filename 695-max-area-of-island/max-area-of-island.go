func maxAreaOfIsland(grid [][]int) int {
    m, n := len(grid), len(grid[0])
    visited := make([][]int, m)
    for i := range visited {
        visited[i] = make([]int, n)
    }

    max_area := 0

    for i := range m {
        for j := range n {
            if grid[i][j] == 1 && visited[i][j] == 0 {
                cnt := 0 // to keep track of size of the island
                
                var q [][2]int
                q = append(q, [2]int{i, j})
                visited[i][j] = 1
                // bfs
                for len(q) > 0 {
                    node := q[0]
                    q = q[1:]

                    r, c := node[0], node[1]

                    cnt++ // processed a cell
                    
                    // up
                    if r > 0 && visited[r-1][c] == 0 && grid[r-1][c] == 1 {
                        q = append(q, [2]int{r-1, c})
                        visited[r-1][c] = 1
                    }
                    // right
                    if c < n-1 && visited[r][c+1] == 0 && grid[r][c+1] == 1 {
                        q = append(q, [2]int{r, c+1})
                        visited[r][c+1] = 1
                    } 
                    // down
                    if r < m-1 && visited[r+1][c] == 0 && grid[r+1][c] == 1 {
                        q = append(q, [2]int{r+1, c})
                        visited[r+1][c] = 1
                    }
                    // left
                    if c > 0 && visited[r][c-1] == 0 && grid[r][c-1] == 1 {
                        q = append(q, [2]int{r, c-1})
                        visited[r][c-1] = 1
                    }
                }
                max_area = max(max_area, cnt)
            }
        }
    }

    return max_area
}