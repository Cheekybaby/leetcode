func allCellsDistOrder(rows int, cols int, rCenter int, cCenter int) [][]int {
    var dist [][]int

    for i := 0; i < rows; i++ {
        for j := 0; j < cols; j++ {
            dist = append(dist, []int{i, j})
        }
    }

    sort.Slice(dist, func(i, j int) bool {
        d1 := abs(dist[i][0] - rCenter) + abs(dist[i][1] - cCenter)
        d2 := abs(dist[j][0] - rCenter) + abs(dist[j][1] - cCenter)

        return d1 < d2
    })


    return dist
}

func abs(x int) int {
    if x < 0 {
        return -1 * x
    }
    return x
}