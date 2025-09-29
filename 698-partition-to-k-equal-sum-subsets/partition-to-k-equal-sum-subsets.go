func solve(nums []int, visited []bool, k, idx, target, sum int) bool {
    if k == 1 {
        return true
    }
    if sum == target {
        return solve(nums, visited, k-1, 0, target, 0)
    }

    for j := idx; j < len(nums); j++ {
        if visited[j] || (sum + nums[j]) > target {
            continue
        }
        visited[j] = true
        if (solve(nums, visited, k, j+1, target, sum + nums[j])) {
            return true
        }
        visited[j] = false
    }
    return false
}

func canPartitionKSubsets(nums []int, k int) bool {
    sum := 0
    for _, val := range nums {
        sum += val
    }

    if (sum % k) != 0 {
        return false
    }
    sort.Sort(sort.Reverse((sort.IntSlice(nums))))
    target := (sum / k)
    visited := make([]bool, len(nums))
    
    return solve(nums, visited, k, 0, target, 0)
}