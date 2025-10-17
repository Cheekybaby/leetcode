func merge(intervals [][]int) [][]int {
    sort.Slice(intervals, func(i, j int) bool {
        if intervals[i][0] == intervals[j][0] {
            return intervals[i][1] < intervals[j][1]
        }
        return intervals[i][0] < intervals[j][0]
    })

    var ans [][]int
    ans = append(ans, intervals[0])
    for i := 1; i < len(intervals); i++ {
        last := ans[len(ans)-1]
        left, right := last[0], last[1]
        l, r := intervals[i][0], intervals[i][1]

        if l > right || r < left {
            ans = append(ans, intervals[i])
        } else {
            ans = ans[:len(ans)-1]
            st := min(l, left)
            end := max(r, right)
            ans = append(ans, []int{st, end})
        }
    }
    return ans
}