func compute(n int) int {
    cnt := 0
    for i := 1; i <= n; i++ {
        x := i
        valid, good := true, false
        for x > 0 {
            digit := x % 10
            
            if digit == 3 || digit == 4 || digit == 7 {
                valid = false
                break
            }

            if digit == 2 || digit == 5 || digit == 6 || digit == 9 {
                good = true
            }

            x /= 10
        }
        if valid && good {
            cnt++
        }
    }
    return cnt
}

func rotatedDigits(n int) int {
    ans := compute(n)
    return ans
}