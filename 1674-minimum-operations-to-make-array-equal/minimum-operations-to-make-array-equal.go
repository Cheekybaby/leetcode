func minOperations(n int) int {
    min_ops := 0
    for i := 1; i < n; i+=2 {
        min_ops += (n - i)
    }

    return min_ops
}