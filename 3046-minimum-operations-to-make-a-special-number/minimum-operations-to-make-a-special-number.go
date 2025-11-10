func minimumOperations(num string) int {
    zero, five := false, false

    for i := len(num)-1; i >= 0; i-- {
        if zero && (num[i] == '0' || num[i] == '5') {
            return (len(num) - i - 2)
        }
        if five && (num[i] == '2' || num[i] == '7') {
            return (len(num) - i - 2)
        }

        if num[i] == '0' {
            zero = true
        } else if num[i] == '5' {
            five = true
        }
    }

    if zero {
        return len(num)-1
    }
    return len(num)
}