func findThePrefixCommonArray(A []int, B []int) []int {
    n := len(A)
    ans, freq := make([]int, n), make([]int, n+1)
    cnt := 0
    for i:=0; i<n; i++ {
        freq[A[i]] += 1
        if freq[A[i]] == 2 {
            cnt += 1
        }

        freq[B[i]] += 1
        if freq[B[i]] == 2 {
            cnt += 1
        }
        ans[i] = cnt
    }
    return ans
}