func setZeroes(matrix [][]int)  {
    var row, col []int
    m, n := len(matrix), len(matrix[0])
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if matrix[i][j] == 0 {
                row = append(row, i)
                col = append(col, j)
            }
        }
    }

    for _, i := range row {
        for j := 0; j < n; j++ {
            matrix[i][j] = 0
        }
    }
    for _, i := range col {
        for j := 0; j < m; j++ {
            matrix[j][i] = 0
        }
    }
}