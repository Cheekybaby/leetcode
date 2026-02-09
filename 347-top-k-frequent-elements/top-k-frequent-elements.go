func topKFrequent(nums []int, k int) []int {
    freq := map[int]int{}
    for _, num := range nums {
        freq[num]++
    }

    buckets := make([][]int, len(nums)+1)
    for num, f := range freq {
        buckets[f] = append(buckets[f], num)
    }
    most_freq := []int{}
    for i := len(buckets)-1; i >= 0; i-- {
        if len(buckets[i]) > 0 {
            for _, num := range buckets[i] {
                most_freq = append(most_freq, num)
                
                if len(most_freq) == k {
                    return most_freq
                }
            }
        }
    }
    return most_freq
}