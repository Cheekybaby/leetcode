func minimumSum(n int, k int) int {
    sum := 0
    cnt := 0
    for i := 1; cnt < n; i += 1 {
        cmp := k - i
        if cmp > i || cmp <= 0 || cmp == i {
            sum += i
            cnt++
        }
    }

    return sum
}