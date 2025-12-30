func digits(num int) int {
    cnt := 0
    for num > 0 {
        cnt += 1
        num /= 10
    }
    return cnt
}

func helper(cnt int) (start, inc int) {
    start, inc = 1, 1
    for i := 2; i <= cnt; i++ {
        start = start * 10 + i
        inc = inc * 10 + 1
    }

    return start, inc
}

func sequentialDigits(low int, high int) []int {
    cnt_s, cnt_e := digits(low), digits(high)
    ans := []int{}
    for i := cnt_s; i <= cnt_e; i++ {
        start, inc := helper(i)

        for j := 0; j < (10 - i); j++ {
            if start >= low && start <= high {
                ans = append(ans, start)
            } else if start > high {
                break
            }
            start += inc
        }
        if start > high {
            break
        }
    }

    return ans
}