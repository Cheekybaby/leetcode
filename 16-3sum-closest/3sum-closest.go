func threeSumClosest(nums []int, target int) int {
    sort.Ints(nums)
    ans := nums[0] + nums[1] + nums[2]
    for i := range nums {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }

        l, r := i+1, len(nums)-1
        
        for l < r {
            sum := nums[i] + nums[l] + nums[r]

            if sum == target {
                return sum
            }

            diff := abs(target - ans)
            new_diff := abs(target - sum)

            if new_diff < diff {
                ans = sum
            
            
            } else if sum > target {
                r--
            } else if sum < target {
                l++
            }
        }
    }
    return ans
}

func abs(a int) int {
    if a < 0 {
        return -1 * a
    }
    return a
}