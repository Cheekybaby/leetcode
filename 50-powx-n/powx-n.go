func pow(x float64, n int) float64 {
    if n == 0 {
        return 1
    }

    if n % 2 == 1 {
        val := pow(x, n/2)
        return x * val * val
    } else {
        val := pow(x, n/2)
        return val * val
    }
}

func myPow(x float64, n int) float64 {
    neg := false
    if n < 0 {
        n *= -1
        neg = true
    }
    ans := pow(x, n)

    if neg {
        return 1/ans
    }
    return ans
}