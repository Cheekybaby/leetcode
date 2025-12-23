func maxCount(banned []int, n int, maxSum int) int {
    sort.Ints(banned)
    sum, cnt := 0, 0
    for i := 1; i <= n; i++ {
        if !binarySearch(banned, i) {
            sum += i
            if sum <= maxSum {
                cnt++
            } else {
                break
            }
        }
    }

    return cnt
}
func binarySearch(banned []int, i int) bool {
    l, r := 0, len(banned)-1
    for l <= r {
        mid := l + (r - l)/2

        if banned[mid] == i {
            return true
        } else if banned[mid] > i {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }

    return false
}