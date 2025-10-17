func insert(intervals [][]int, newInterval []int) [][]int {
    var ans [][]int
    i := 0
    for i < len(intervals) && intervals[i][1] < newInterval[0] {
        ans = append(ans, intervals[i])
        i++
    }

    for i < len(intervals) && intervals[i][0] <= newInterval[1] {
        start := min(intervals[i][0], newInterval[0])
        end := max(intervals[i][1], newInterval[1])

        newInterval = []int{start, end}
        i+=1
    }

    ans = append(ans, newInterval)

    for i < len(intervals) {
        ans = append(ans, intervals[i])
        i++
    }
    
    return ans
}