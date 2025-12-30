func reverse(num int) int {
    rev := 0
    for num > 0 {
        rem := num % 10
        rev = rev * 10 + rem
        num /= 10
    }

    return rev
}

func sumOfNumberAndReverse(num int) bool {
    for i := 0; i <= num; i++ {
        curr := i
        rev := reverse(i)

        if curr + rev == num {
            return true
        }
    }

    return false
}