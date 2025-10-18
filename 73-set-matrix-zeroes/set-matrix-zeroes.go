func setZeroes(matrix [][]int)  {
    cell := matrix[0][0]
    m, n := len(matrix), len(matrix[0])
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if matrix[i][j] == 0 {
                if j == 0 {
                    cell = 0
                }
                matrix[i][0] = 0
            }
        }
    }

    for i := 0; i < m; i++ {
        if matrix[i][0] == 0 {
            // row
            for j := 1; j < n; j++ {
                if matrix[i][j] == 0 {
                    // col
                    for k := 0; k < m; k++ {
                        matrix[k][j] = 0
                    }
                } else {
                    matrix[i][j] = 0
                }
            }
        }
    }

    if cell == 0 {
        for i := 0; i < m; i++ {
            matrix[i][0] = 0
        }
    }
}