func chalkReplacer(chalk []int, k int) int {
    for i := 1; i < len(chalk); i++ {
        chalk[i] += chalk[i-1]
    }

    k %= chalk[len(chalk)-1]

    // find the upper bound of k in the prefix array chalk
    ans := upperBound(chalk, k)

    return ans
}

func upperBound(chalk []int, k int) int {
    i, j := 0, len(chalk)-1
    for i <= j {
        mid := i + (j - i)/2
        if chalk[mid] <= k {
            i = mid + 1
        } else {
            j = mid - 1
        }
    }

    return i
}