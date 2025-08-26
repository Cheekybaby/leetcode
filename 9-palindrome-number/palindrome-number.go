func isPalindrome(x int) bool {
    if x < 0 {
        return false
    }
    y := x
    rev := 0
    for y > 0 {
        rem := y % 10
        rev = rev * 10 + rem

        y/=10
    }

    if rev == x {
        return true
    }
    return false
}