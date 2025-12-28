func sortMatrix(grid [][]int) [][]int {
    n := len(grid)
    n_diag := (2 * n) - 1
    var asc bool = false
    for d := 0; d < n_diag; d++ {
        diag := []int{}
        for r := 0; r < n; r++ {
            c := r + d - (n - 1)

            if c >= 0 && c < n {
                diag = append(diag, grid[r][c])
            }
        }

        fmt.Println(diag)

        if asc {
            sort.Ints(diag)
        } else {
            sort.Slice(diag, func (i, j int) bool {
                return diag[i] > diag[j]
            })
        }

        fmt.Println(diag)
        fmt.Println()

        k := 0
        for r := 0; r < n; r++ {
            c := r + d - (n - 1)

            if c >= 0 && c < n {
                grid[r][c] = diag[k]
                k++
            }
        }
        if d == (n_diag / 2) {
            asc = true
        }
    }
    return grid
}