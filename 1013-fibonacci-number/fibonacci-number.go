func fib(n int) int {
    if n == 0 || n == 1 {
        return n
    }
    f, s := 0, 1
    for i := 2; i <= n; i++ {
        tmp := f + s
        f = s
        s = tmp
    }
    return s
}