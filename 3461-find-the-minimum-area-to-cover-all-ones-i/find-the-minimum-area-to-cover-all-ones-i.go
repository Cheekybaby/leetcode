func minimumArea(grid [][]int) int {
    m, n := len(grid), len(grid[0])
    var up, right, down, left int = m, -1, -1, n
    cnt := 0
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == 1 {
                cnt++
                left = min(left, j)
                up = min(up, i)
                right = max(right, j)
                down = max(down, i)
            }
        }
    }

    if cnt == 0 {
        return 0
    }

    length := down - up + 1
    breadth := right - left + 1

    return length * breadth
}