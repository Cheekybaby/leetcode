func rangeAddQueries(n int, queries [][]int) [][]int {
    diff := make([][]int, n+1)
    for i := range diff {
        diff[i] = make([]int, n+1)
    }

    for _, query := range queries {
        r1, r2 := query[0], query[2]
        c1, c2 := query[1], query[3]

        diff[r1][c1] += 1
        diff[r2+1][c1] -= 1
        diff[r1][c2+1] -= 1
        diff[r2+1][c2+1] += 1
    }

    matrix := make([][]int, n)
    for i := range matrix {
        matrix[i] = make([]int, n)
    }

    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            up, diag, left := 0, 0, 0
            if i > 0 {
                up = matrix[i-1][j]
            }
            if j > 0 {
                left = matrix[i][j-1]
            }
            if i > 0 && j > 0 {
                diag = matrix[i-1][j-1]
            }

            matrix[i][j] = diff[i][j] + up + left - diag
        }
    }

    return matrix
}