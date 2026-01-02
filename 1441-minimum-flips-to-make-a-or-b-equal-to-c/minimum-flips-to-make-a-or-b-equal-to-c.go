func toBinary(n int) []int {
    bin_string := make([]int, 32)
    for i := 0; i < 32; i++ {
        bit := n & 1
        bin_string[i] = bit
        n >>= 1
    }

    return bin_string
}

func minFlips(a int, b int, c int) int {
    bin_a, bin_b, bin_c := toBinary(a), toBinary(b), toBinary(c)
    flip := 0
    for i := 0; i < 32; i++ {
        or := bin_a[i] | bin_b[i]
        res := bin_c[i]
        if or != res {
            if res == 1 {
                flip++
            } else {
                if bin_a[i] == 1 {
                    flip++
                }
                if bin_b[i] == 1 {
                    flip++
                }
            }
        }
    }

    return flip
}