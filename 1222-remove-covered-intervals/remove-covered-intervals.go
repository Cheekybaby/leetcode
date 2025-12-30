func removeCoveredIntervals(intervals [][]int) int {
    sort.Slice(intervals, func (i, j int) bool {
        if intervals[i][0] == intervals[j][0] {
            return intervals[i][1] > intervals[j][1]
        }
        return intervals[i][0] < intervals[j][0]
    })

    merged := [][]int{}
    for i := 0; i < len(intervals); {
        curr := intervals[i]
        j := i + 1
        for j < len(intervals) {
            next := intervals[j]
            if curr[0] <= next[0] && curr[1] >= next[1] {
                j++
            } else {
                break
            }
        }
        merged = append(merged, curr)
        i = j
    }

    return len(merged)
}