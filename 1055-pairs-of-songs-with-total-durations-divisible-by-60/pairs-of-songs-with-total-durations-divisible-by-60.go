func numPairsDivisibleBy60(time []int) int {
    for i := range time {
        time[i] %= 60
    }

    pairs := 0
    seen := map[int]int{}
    for i := range time {
        toFind := (60 - time[i]) % 60
        if val, ok := seen[toFind]; ok {
            pairs += val
        }
        seen[time[i]]++
    }
    return pairs
}