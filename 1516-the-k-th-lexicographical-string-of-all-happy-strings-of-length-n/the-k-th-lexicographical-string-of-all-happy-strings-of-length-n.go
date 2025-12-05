func getHappyString(n int, k int) string {
    total_possible := 3 * (pow(2, n-1))
    if n == 1 {
        total_possible = 3
    }

    if k > total_possible {
        return ""
    }

    chars := []byte{'a','b','c'}
    final := make([]byte, n)
    // now we need to build the string according to the ranking
    for i := 0; i < n; i++ {
        var choices []byte

        if i == 0 {
            choices = chars
        } else {
            last := final[i-1]
            for _, c := range chars {
                if c != last {
                    choices = append(choices, c)
                }
            }
        }

        remaining := n - i - 1
        blockSize := pow(2, remaining)

        for _, c := range choices {
            if k > blockSize {
                k -= blockSize
                continue
            }
            final[i] = c
            break
        }
    }

    return string(final)
}

func pow(n, k int) int {
    if k == 0 {
        return 1
    }
    if k == 1 {
        return n
    }

    if k % 2 == 0 {
        val := pow(n, k/2)
        return val * val
    } else {
        val := pow(n, k/2)
        return n * val * val
    }
}