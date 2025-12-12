func longestConsecutive(nums []int) int {
    max_len := 0
    values := map[int]bool{}

    for _, num := range nums {
        values[num] = true
    }

    for key, _ := range values {
        if _, ok := values[key-1]; !ok {
            l := 1
            for l < len(nums) {
                if _, ok := values[key+l]; !ok {
                    break
                }
                l++
            }
            max_len = max(max_len, l)
        }
    }

    return max_len
}