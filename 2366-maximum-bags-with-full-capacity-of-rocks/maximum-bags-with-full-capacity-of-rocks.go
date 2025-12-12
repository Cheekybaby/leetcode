func maximumBags(capacity []int, rocks []int, additionalRocks int) int {
    difference := make([]int, len(capacity))
    for i := range capacity {
        difference[i] = capacity[i] - rocks[i]
    }

    sort.Ints(difference)
    cnt := 0
    for i := range difference {
        if difference[i] == 0 {
            cnt++
        } else {
            if difference[i] <= additionalRocks {
                additionalRocks -= difference[i]
                cnt++
            } else {
                break
            }
        }
    }
    return cnt
}