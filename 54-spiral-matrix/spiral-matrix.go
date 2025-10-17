func spiralOrder(matrix [][]int) []int {
    m := len(matrix)
    n := len(matrix[0])

    var traversal []int

    left, right := 0, n-1
    top, bottom := 0, m-1

    for left <= right && top <= bottom {
        // top
        for i := left; i <= right; i++ {
            traversal = append(traversal, matrix[top][i])
        }
        top++
        // right
        for i := top; i <= bottom; i++ {
            traversal = append(traversal, matrix[i][right])
        }
        right--
        // bottom
        if top <= bottom {
            for i := right; i >= left; i-- {
                traversal = append(traversal, matrix[bottom][i])
            }
            bottom--
        }
        // left
        if left <= right {
            for i := bottom; i >= top; i-- {
                traversal = append(traversal, matrix[i][left])
            }
            left++
        }
    }

    return traversal
}