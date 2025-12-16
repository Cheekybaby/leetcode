func minOperations(n int) int {
    if n == 1 {
        return 0
    }
    min_ops := 0
    if n & 1 == 0 {
        min_ops = (n/2) * (n/2)
    } else {
        min_ops = (n/2) * (n/2 + 1)
    }
    return min_ops
}