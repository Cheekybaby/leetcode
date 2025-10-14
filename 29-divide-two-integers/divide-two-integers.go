func divide(dividend int, divisor int) int {
    if dividend == 0 {
        return 0
    }

    if divisor == 1 {
        return dividend
    } else if divisor == -1 {
        quo := -1 * dividend
        fmt.Println(quo)
        if quo > math.MaxInt32 {
            return math.MaxInt32
        }
        return quo
    }

    dividend_neg, divisor_neg := false, false
    if dividend <  0 {
        dividend *= -1
        dividend_neg = true
    } 
    if divisor < 0 {
        divisor *= -1
        divisor_neg = true
    }

    sum := divisor
    quo := 0
    for dividend >= sum {
        quo++
        sum += divisor
    }

    if (dividend_neg == true && divisor_neg == false) || (dividend_neg == false && divisor_neg == true) {
        return -1 * quo
    }

    return quo
}