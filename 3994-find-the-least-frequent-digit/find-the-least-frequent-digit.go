func getLeastFrequentDigit(n int) int {
    freq := make(map[int]int)

    for n > 0 {
        digits := n % 10
        freq[digits]++
        n/=10
    }
    minFreq := 100
    ans := 10
    for i, f := range freq {
        if f <= minFreq {
            if minFreq == f {
                ans = min(ans, i)
            } else {
                ans = i
            }
            minFreq = min(minFreq, f)
        }
    }

    return ans
}