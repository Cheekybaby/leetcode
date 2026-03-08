func dfs(matrix [][]int, r, c, prev int, memo [][]int) int {
    if r < 0 || r >= len(matrix) || c < 0 || c >= len(matrix[0]) || matrix[r][c] <= prev || matrix[r][c] == -1 {
        return 0
    }

    if memo[r][c] != -1 { return memo[r][c] }

    curr := matrix[r][c]

    matrix[r][c] = -1
    left := dfs(matrix, r, c - 1, curr, memo)
    right := dfs(matrix, r, c + 1, curr, memo) 
    up := dfs(matrix, r - 1, c, curr, memo)
    down := dfs(matrix, r + 1, c, curr, memo)

    matrix[r][c] = curr

    memo[r][c] = 1 + max(left, max(right, max(up, down)))

    return memo[r][c]
}

func longestIncreasingPath(matrix [][]int) int {
    n, m := len(matrix), len(matrix[0])
    memo := make([][]int, n)
    for i := range memo {
        memo[i] = make([]int, m)
        for j := range memo[i] {
            memo[i][j] = -1
        }
    }
    var max_len int
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            length := dfs(matrix, i, j, -1, memo)
            max_len = max(max_len, length)
        }
    }

    return max_len
}