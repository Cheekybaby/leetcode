func numSteps(s string) int {
    carry := 0
    ops := 0
    for i := len(s)-1; i > 0; i-- {
        if carry == 1 {
            if s[i] == '1' {
                ops += 1
                carry = 1
            } else {
                ops += 2
                carry = 1
            }
        } else {
            if s[i] == '1' {
                ops += 2
                carry = 1
            } else {
                ops += 1
            }
        }
    }

    return ops + carry
}