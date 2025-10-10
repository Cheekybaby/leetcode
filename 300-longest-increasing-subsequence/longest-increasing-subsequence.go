func lengthOfLIS(nums []int) int {
    n := len(nums)
    length := make([]int, n)
    for i := range length {
        length[i] = 1
    }

    for i := range nums {
        for j:=0; j<i; j++ {
            if nums[j] < nums[i] {
                len := (length[j] + 1)
                if len > length[i] {
                    length[i] = len
                }
            }
        }
    }
    max_len := 0
    for _, val := range length {
        max_len = max(max_len, val)
    }

    return max_len
}