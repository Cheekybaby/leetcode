type Update struct {
    row1    int
    row2    int
    col1    int
    col2    int
    val     int
}

type SubrectangleQueries struct {
    matrix   [][]int
    updates  []Update
}


func Constructor(rectangle [][]int) SubrectangleQueries {
    return SubrectangleQueries {
        matrix  :    rectangle,
        updates :   make([]Update, 0),
    }
}


func (this *SubrectangleQueries) UpdateSubrectangle(row1 int, col1 int, row2 int, col2 int, newValue int)  {
    this.updates = append(this.updates, Update{
        row1 : row1,
        row2 : row2,
        col1 : col1,
        col2 : col2,
        val  : newValue,
    })
}


func (this *SubrectangleQueries) GetValue(row int, col int) int {
    for i := len(this.updates) - 1; i >= 0; i-- {
        update := this.updates[i]

        if update.row1 <= row && update.row2 >= row && update.col1 <= col && update.col2 >= col {
            return update.val
        }
    }
    return this.matrix[row][col]
}


/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * obj := Constructor(rectangle);
 * obj.UpdateSubrectangle(row1,col1,row2,col2,newValue);
 * param_2 := obj.GetValue(row,col);
 */