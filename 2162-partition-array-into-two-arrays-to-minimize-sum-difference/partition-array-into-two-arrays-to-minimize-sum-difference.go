func generateSubsetSum(nums []int) [][]int {
    m := len(nums)
    buckets := make([][]int, m + 1)
    tot_subsets := (1 << m)

    for mask := 0; mask < tot_subsets; mask++ {
        cnt := 0
        sum := 0
        for i := 0; i < m; i++ {
            if ((mask >> i) & 1) == 1 {
                cnt += 1
                sum += nums[i]
            }
        }
        buckets[cnt] = append(buckets[cnt], sum)
    }

    return buckets
}
func minimumDifference(nums []int) int {
    n := len(nums)/2
    left := nums[:n]
    right := nums[n:]

    tot_sum := 0
    for _, num := range nums {
        tot_sum += num
    }

    left_subset := generateSubsetSum(left)
    right_subset := generateSubsetSum(right)

    for i := range right_subset {
        sort.Ints(right_subset[i])
    }

    min_diff := math.MaxInt
    for i := range left_subset {
        for j := range left_subset[i] {
            l := left_subset[i][j]
            to_find := (tot_sum / 2 ) - l
            r := binarySearch(right_subset[n - i], to_find)

            sum := l + r
            diff := abs(tot_sum - (2 * sum))

            min_diff = min(min_diff, diff)
        }
    }
    return min_diff
}

func binarySearch(nums []int, target int) int {
    l, r := 0, len(nums)-1
    for l <= r {
        mid := l + (r - l)/2

        if nums[mid] == target {
            return nums[mid]
        } else if nums[mid] > target {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }

    if r < 0 { return nums[l] }
    if l >= len(nums) { return nums[r] }

    if abs(nums[l] - target) < abs(nums[r] - target) {
        return nums[l]
    }
    return nums[r]
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}