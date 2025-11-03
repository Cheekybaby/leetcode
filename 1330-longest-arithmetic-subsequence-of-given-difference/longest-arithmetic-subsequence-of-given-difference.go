func longestSubsequence(arr []int, difference int) int {
    mp := make(map[int]int)

    for i := range arr {
        last := arr[i] - difference

        val, ok := mp[last]

        if ok {
            mp[arr[i]] = val + 1
        } else {
            mp[arr[i]] = 1
        }
    }

    max_len := 1

    for _, val := range mp {
        max_len = max(max_len, val)
    }

    return max_len
}