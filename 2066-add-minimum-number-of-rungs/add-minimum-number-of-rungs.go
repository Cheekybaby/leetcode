func addRungs(rungs []int, dist int) int {
    cnt := 0
    curr := 0
    for i := range rungs {
        next_rung := rungs[i]
        reach := curr + dist

        if reach < next_rung {
            diff := next_rung - curr
            cnt += (diff / dist)
            if diff % dist == 0 {
                cnt -= 1
            }
        }

        curr = next_rung
    }

    return cnt
}