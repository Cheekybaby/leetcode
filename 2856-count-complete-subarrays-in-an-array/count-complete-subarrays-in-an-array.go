func countDistinct(nums []int) int {
    seen := map[int]bool{}
    for _, num := range nums {
        if _, ok := seen[num]; !ok {
            seen[num] = true
        }
    }

    return len(seen)
}

func countCompleteSubarrays(nums []int) int {
    distinct := countDistinct(nums)
    subarrays := 0
    seen := map[int]int{}
    j := 0
    for i := 0; i < len(nums); i++ {
        if i > 0 {
            seen[nums[i-1]]--

            if val, ok := seen[nums[i-1]]; ok {
                if val == 0 {
                    delete(seen, nums[i-1])
                }
            }
        }

        for j < len(nums) && len(seen) < distinct {
            seen[nums[j]]++
            j++
        }

        if len(seen) == distinct {
            subarrays += (len(nums) - j + 1)
        }
    }

    return subarrays
}