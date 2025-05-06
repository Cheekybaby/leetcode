func topKFrequent(nums []int, k int) []int {
    bucket := make([][]int, len(nums)+1)
    freq := make(map[int]int)
    var ans []int
    for _, num := range nums {
        freq[num]++
    }

    for k, v := range freq {
        bucket[v] = append(bucket[v], k)
    }


    for i := len(bucket)-1; i>=0 && k > 0 ; i-- {
        buck := bucket[i]
        for j:=0; j<len(buck); j++ {
            ans = append(ans, buck[j])
            k--
        }
    }

    return ans
}