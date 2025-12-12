func kthFactor(n int, k int) int {
    cnt := 0
    for i := 1; i*i < n; i++ {
        if n % i == 0 {
            cnt++
        }

        if cnt == k {
            return i
        }
    }
    x := int(math.Sqrt(float64(n)))

    for i := x; i >= 1; i-- {
        if n % i == 0 {
            cnt++
        }

        if cnt == k {
            return n / i
        }
    }

    return -1
}