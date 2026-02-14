func champagneTower(poured int, query_row int, query_glass int) float64 {
    var grid [102][102]float64
    grid[0][0] = float64(poured)
    for i := 0; i <= query_row; i++ {
        for j := 0; j <= i; j++ {
            var q float64 = (grid[i][j] - 1.0) / 2.0
            if (q > 0) {
                grid[i+1][j] += q;
                grid[i+1][j+1] += q;
            }
        }
    }

    return min(1, grid[query_row][query_glass])
}