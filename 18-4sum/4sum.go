func fourSum(nums []int, target int) [][]int {
    sort.Ints(nums)
    var ans [][]int
    for i := 0; i < len(nums); i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        first := nums[i]
        for j := i + 1; j < len(nums); j++ {
            if j > i+1 && nums[j] == nums[j-1] {
                continue
            }
            second := nums[j]
            l, r := j + 1, len(nums)-1
            for l < r {
                sum := first + second + nums[l] + nums[r]
                if sum == target {
                    temp := []int{first, second, nums[l], nums[r]}
                    ans = append(ans, temp)


                    l++
                    r--

                    for l < r && nums[l] == nums[l-1] {
                        l++
                    }
                    for l < r && nums[r] == nums[r+1] {
                        r--
                    }
                } else if sum > target {
                    r--
                } else {
                    l++
                }
            }
        }
    }

    return ans
}