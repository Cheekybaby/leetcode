func minimumSum(n int, k int) int {
    sum := 0
    cnt := 0
    avoid := map[int]bool{}
    for i := 1; cnt < n; i += 1 {
        if _, ok := avoid[i]; !ok {
            sum += i
            cnt++
            avoid[k - i] = true
        }
    }

    return sum
}