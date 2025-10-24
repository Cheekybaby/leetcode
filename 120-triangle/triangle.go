func minimumTotal(triangle [][]int) int {
    m := len(triangle)
    for i := 1; i < m; i++ {
        n := len(triangle[i])

        for j := 0; j < n; j++ {
            prev := math.MaxInt
            if j > 0 {
                prev = triangle[i-1][j-1]
            }
            curr := math.MaxInt
            if j < n-1 {
                curr = triangle[i-1][j]
            }

            triangle[i][j] = triangle[i][j] + min(prev, curr)
        }
    }

    min_path_sum := math.MaxInt
    n := len(triangle[m-1])

    for i := 0; i < n; i++ {
        min_path_sum = min(min_path_sum, triangle[m-1][i])
    }

    return min_path_sum
}