func climbStairs(n int) int {
    first, second := 1, 1

    for i := 2; i <= n; i++ {
        sum := first + second
        first = second
        second = sum
    }

    return second
}