func topKFrequent(nums []int, k int) []int {
    buckets := make([][]int, len(nums))
    freq := map[int]int{}

    for _, num := range nums {
        freq[num]++
    }

    for key, val := range freq {
        buckets[val-1] = append(buckets[val-1], key)
    }

    var ans []int
    for i := len(buckets)-1; i >= 0 && k > 0; i-- {
        elements := buckets[i]
        if len(elements) > 0 {
            for _, ele := range elements {
                ans = append(ans, ele)
                k--
            }
        }
    }
    return ans
}