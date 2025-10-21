func grayCode(n int) []int {
    size := (1 << n)
    gray := make([]int, size)
    for i := 1; i < size; i++ {
        gray[i] = i ^ (i >> 1)
    }

    return gray
}