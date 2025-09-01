const mod = 1000000007
/*
- The dfs will take the following input:
    - The grid, the index it is at right now (i, j)
    - And also a simple variable telling it which direction the robot took
        - If the robot took right to come here, it will be 1
        - If the robot took down to come here, it will be 0
*/

func dfs(grid [][]int, i, j int, dir int, dp [][][]int) int {
    n, m := len(grid), len(grid[0])
    // Check for out of bounds
    if i >=n || j >= m {
        return 0
    }
    if i == n-1 && j == m-1 { // We reached the end
        return 1
    }

    if dp[i][j][dir] != -1 {
        return dp[i][j][dir]
    }

    if grid[i][j] == 1 {
        if dir == 1 {
            // We move to the bottom cell
            return dfs(grid, i+1, j, 0, dp)
        } else {
            return dfs(grid, i, j+1, 1, dp)
        }
    }

    move := 0
    move += dfs(grid, i+1, j, 0, dp) + dfs(grid, i, j+1, 1, dp)
    
    dp[i][j][dir] = move % mod
    
    return dp[i][j][dir]
}

func uniquePaths(grid [][]int) int {
    dp := initializeDP(len(grid), len(grid[0]))
    paths := dfs(grid, 0, 0, 0, dp) % mod

    return paths
}

func initializeDP(n, m int) (matrix [][][]int) {
    matrix = make([][][]int, n+1)
    for i := range matrix {
        matrix[i] = make([][]int, m+1)
        for j := range matrix[i] {
            matrix[i][j] = make([]int, 2)
            for k := range matrix[i][j] {
                matrix[i][j][k] = -1
            }
        }
    }
    return matrix
}