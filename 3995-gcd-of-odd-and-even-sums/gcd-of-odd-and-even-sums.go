func gcdOfOddEvenSums(n int) int {
    sumOfOdds := n * n
    sumOfN := n * (2*n + 1)
    sumOfEvens := sumOfN - sumOfOdds

    return gcd(sumOfOdds, sumOfEvens)
}

func gcd(a, b int) int {
    for b > 0 {
        rem := a % b
        a = b
        b = rem
    }
    return a
}