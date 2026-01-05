func countCompleteDayPairs(hours []int) int64 {
    var cnt int64
    seen := map[int]int{}

    for i := range hours {
        hours[i] %= 24
    }

    for _, h := range hours {
        pair := (24 - h) % 24

        if val, ok := seen[pair]; ok {
            cnt += int64(val)
        }

        seen[h]++
    }

    return cnt
}