func rotate(matrix [][]int)  {
    for i := range matrix {
        for j := 0; j <= i; j++ {
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        }
    }

    for i := range matrix {
        reverse(matrix[i])
    }
}

func reverse(row []int) {
    l, r := 0, len(row)-1
    for l < r {
        row[l], row[r] = row[r], row[l]
        l++
        r--
    }
}