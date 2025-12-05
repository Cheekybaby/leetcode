func colorBorder(grid [][]int, row int, col int, color int) [][]int {
    m, n := len(grid), len(grid[0])
    directions := [][]int{{0, 1}, {0,-1}, {1,0}, {-1,0}}
    root := []int{row, col}
    visited := make([][]int, m)
    for i := range visited {
        visited[i] = make([]int, n)
    }

    var q [][]int
    q = append(q, root)
    visited[row][col] = 1

    connected_color := grid[row][col]
    var border [][]int
    for len(q) > 0 {
        r, c := q[0][0], q[0][1]
        q = q[1:]
        isBorder := false
        for _, d := range directions {
            dr, dc := r + d[0], c + d[1]

            if (dr >= 0 && dr < m) && (dc >= 0 && dc < n) {
                if grid[dr][dc] == connected_color {
                    if visited[dr][dc] == 0 {
                        visited[dr][dc] = 1
                        q = append(q, []int{dr, dc})
                    }
                } else {
                    isBorder = true
                }
            } else {
                isBorder = true
            }
            if isBorder == true {
                border = append(border, []int{r, c})
            }
        }
    }

    for _, coor := range border {
        r, c := coor[0], coor[1]
        grid[r][c] = color
    }

    return grid
}