func decrypt(code []int, k int) []int {
    n := len(code)
    ans := make([]int, n)
    if k > 0 {
        for i:=0; i<n; i++ {
            sum := 0
            for j:=1; j<=k; j++ {
                sum += code[(i + j) % n]
            }
            ans[i] = sum
        }
    } else if k < 0 {
        k = -k
        for i:=0; i<n; i++ {
            sum := 0
            for j:=1; j<=k; j++ {
                sum += code[(i - j + n) % n]
            }
            ans[i] = sum
        }
    }
    return ans
}