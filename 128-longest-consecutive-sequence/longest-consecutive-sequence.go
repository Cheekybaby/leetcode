func longestConsecutive(nums []int) int {
    seen := map[int]bool{}
    for i := 0; i < len(nums); i++ {
        seen[nums[i]] = true
    }

    max_len := 0

    for key, _ := range seen {
        if _, ok := seen[key-1]; !ok {
            length := 1
            for length < len(nums) {
                _, ok := seen[key + length]
                if ok {
                    length++
                } else {
                    break;
                }
            }
            max_len = max(max_len, length)
        }
    }

    return max_len
}