func allCellsDistOrder(rows int, cols int, rCenter int, cCenter int) [][]int {
    dist := make(map[int][][]int)
    for i := 0; i < rows; i++ {
        for j := 0; j < cols; j++ {
            distance := abs(i - rCenter) + abs(j - cCenter)
            dist[distance] = append(dist[distance], []int{i, j})
        }
    }
    fmt.Println(dist)
    var sorted [][]int
    
    max_dist := (rows + cols)
    for i := 0; i <= max_dist; i++ {
        if val, ok := dist[i]; ok {
            for j := range val {
                sorted = append(sorted, val[j])
            }
        }
    }

    return sorted
}
func abs(x int) int {
    if x < 0 {
        return - 1 * x
    }
    return x
}