func myPow(x float64, n int) float64 {
    return findPow(x, n)
}

func findPow(x float64, n int) float64 {
    if n == 0 {
        return 1
    }

    if n < 0 {
        return 1.0/findPow(x, -n)
    }

    if (n % 2) == 1 {
        res := findPow(x, n/2)
        return x * res *  res
    } else {
        res := findPow(x, n/2)
        return res * res
    }
}