func maxSum(grid [][]int) int {
    max_sum := 0
    for i := 1; i < len(grid)-1; i++ {
        for j := 1; j < len(grid[0])-1; j++ {
            center := grid[i][j]
            top := grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1]
            bottom := grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1]

            sum := top + center + bottom

            max_sum = max(max_sum, sum)
        }
    }

    return max_sum
}