func generateSubsetSum(nums []int) [][]int {
    m := len(nums)
    buckets := make([][]int, m+1)
    total_subsets := (1 << m)
    for mask:=0; mask < total_subsets; mask++ {
        count := 0
        sum := 0
        for i := 0; i < m; i++ {
            if ((mask >> i) & 1) == 1 {
                count += 1
                sum += nums[i]
            }
        }
        buckets[count] = append(buckets[count], sum)
    }
    return buckets
}
func minimumDifference(nums []int) int {
    n := len(nums)/2
    left := nums[:n]
    right := nums[n:]

    left_sum_subset := generateSubsetSum(left)
    right_sum_subset := generateSubsetSum(right)

    for i := range right_sum_subset {
        sort.Ints(right_sum_subset[i])
    }
    var total int 
    for _, val := range nums {
        total += val
    }
    
    minDiff := math.MaxInt

    for k := 0; k < n; k++ {
        for _, sumLeft := range left_sum_subset[k] {
            pair := (n - k)
            candidates := right_sum_subset[pair]
            target := (total / 2 - sumLeft)

            sumRight := binarySearch(candidates, target)

            sumL := sumLeft + sumRight
            diff := abs(total - (2 * sumL))

            minDiff = min(minDiff, diff)
        }
    }

    return minDiff
}
func abs (x int) int {
    if x < 0 {
        return -1 * x
    }
    return x
}
func binarySearch(nums []int, target int) int {
    left, right := 0, len(nums)-1
    for left <= right {
        mid := (left + (right - left)/2)
        if nums[mid] == target {
            return nums[mid]
        } else if nums[mid] > target {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
    if left >= len(nums) {
        return nums[right]
    } else if right < 0 {
        return nums[left]
    }

    if abs(nums[left] - target) < abs(nums[right] - target) {
        return nums[left]
    } else {
        return nums[right]
    }
}
