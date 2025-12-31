func countPoints(points [][]int, queries [][]int) []int {
    ans := make([]int, len(queries))
    for i, query := range queries {
        xc, yc, r := query[0], query[1], query[2]
        cnt := 0
        for _, point := range points {
            x, y := point[0], point[1]
            x_diff, y_diff := abs(xc - x), abs(yc - y)

            dist := (x_diff * x_diff) + (y_diff * y_diff)

            if dist <= (r * r) {
                cnt++
            }
        }
        ans[i] = cnt
    }

    return ans
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}