func solve(n int) int {
    if n == 0 {
        return 0
    }
    if n == 1 {
        return 1
    }
    return solve(n-1) + solve(n-2)
}
func fib(n int) int {
    return solve(n)
}