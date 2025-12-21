func numOfSubarrays(arr []int, k int, threshold int) int {
    cnt := 0
    j, sum := 0, 0
    for i := 0; i < len(arr); i++ {
        sum += arr[i]
        win_len := i - j + 1
        if win_len == k {
            average := (sum / win_len)

            if average >= threshold {
                cnt++
            }

            sum -= arr[j]
            j++
        }
    }

    return cnt
}