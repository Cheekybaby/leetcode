func climbStairs(n int) int {
    if n == 1 || n == 2 {
        return n
    }
    f, s := 1, 2
    for i := 3; i <= n; i++ {
        tmp := f + s
        f = s
        s = tmp
    }
    return s
}