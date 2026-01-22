func climbStairs(n int) int {
    a, b := 1, 1
    for i := 2; i <= n; i++ {
        temp := a + b
        a = b
        b = temp
    }

    return b
}