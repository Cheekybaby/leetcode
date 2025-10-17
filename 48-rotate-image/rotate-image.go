func rotate(matrix [][]int)  {
    n := len(matrix)
    for i := 0; i < n; i++ {
        for j := 0; j <= i; j++ {
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        }
    }

    for i := 0; i < n; i++ {
        row := matrix[i]
        reverse(row)
        matrix[i] = row
    }
}
func reverse(row []int) {
    i, j := 0, len(row)-1
    for i < j {
        row[i], row[j] = row[j], row[i]
        i++
        j--
    }
}