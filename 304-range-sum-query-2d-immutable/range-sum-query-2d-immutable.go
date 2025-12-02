type NumMatrix struct {
    prefix [][]int
}


func Constructor(matrix [][]int) NumMatrix {
    temp := matrix
    m, n := len(matrix), len(matrix[0])
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            l, u, d := 0, 0, 0
            if j > 0 {
                l = temp[i][j-1]
            }
            if i > 0 {
                u = temp[i-1][j]
            }
            if i > 0 && j > 0 {
                d = temp[i-1][j-1]
            }

            temp[i][j] += (l + u - d)
        }
    }

    return NumMatrix{prefix : temp,}
}


func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
    var x, a, b, c int
    x = this.prefix[row2][col2]
    if row1 > 0 {
        a = this.prefix[row1-1][col2]
    }
    if col1 > 0 {
        b = this.prefix[row2][col1-1]
    }
    if row1 > 0 && col1 > 0 {
        c = this.prefix[row1-1][col1-1]
    }

    return (x - (a + b - c))
}


/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */