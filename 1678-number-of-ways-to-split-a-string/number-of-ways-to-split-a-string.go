const mod = 1000000007
func numWays(s string) int {
    n := len(s)
    prefix := make([]int, n)

    if s[0] == '1' {
        prefix[0] = 1
    }

    for i := 1; i < n; i++ {
        prefix[i] = prefix[i-1]

        if s[i] == '1' {
            prefix[i] += 1
        }
    }

    ones := prefix[n-1]

    if ones % 3 != 0 {
        return 0
    }

    ways := 0
    if ones == 0 {
        ways = (((n-1) * (n-2))/2) % mod
    } else {
        // for string 1
        st1, end1 := lowerBound(prefix, ones/3), upperBound(prefix, ones/3)
        first := (end1 - st1)
        // for string 2
        st2, end2 := lowerBound(prefix, (2*(ones/3))), upperBound(prefix, (2*(ones/3)))
        second := (end2 - st2)

        ways = ((first * second)) % mod
    }
    return ways
}

func lowerBound(nums []int, target int) int {
    l, r := 0, len(nums)-1

    for l <= r {
        mid := l + (r - l)/2

        if nums[mid] >= target {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }

    return l
}
func upperBound(nums []int, target int) int {
    l, r := 0, len(nums)-1

    for l <= r {
        mid := l + (r - l)/2

        if nums[mid] <= target {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }

    return l
}