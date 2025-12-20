func findThePrefixCommonArray(A []int, B []int) []int {
    n := len(A)
    prefix := make([]int, n+1)
    map_a, map_b := map[int]bool{}, map[int]bool{}
    for i := range n {
        prefix[i+1] = prefix[i]
        if A[i] == B[i] {
            prefix[i+1] += 1
        } else {
            cnt := 0
            if _, ok := map_a[B[i]]; ok {
                cnt++
            }
            if _, ok := map_b[A[i]]; ok {
                cnt++
            }
            prefix[i+1] += cnt
        }
        map_a[A[i]] = true
        map_b[B[i]] = true
    }

    return prefix[1:]
}