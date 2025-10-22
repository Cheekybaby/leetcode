func isValid(s string) bool {
    pow := 1
    num := 0

    j := 0
    for ; j < len(s); j++ {
        if s[j] != 0 {
            break
        }
    }

    if j > 0 {
        return false
    }

    for i := len(s)-1; i >= j; i-- {
        digit := int(s[i] - '0')

        num += (digit * pow)
        pow *= 10
    }

    if num >= 0 && num <= 255 && strconv.Itoa(num) == s {
        return true
    }

    return false
}

func restoreIpAddresses(s string) []string {
    var validIPs []string
    n := len(s)

    for i := 1; i < 4; i++ {
        for j := i+1; j < i + 4; j++ {
            for k := j + 1; k < j + 4; k++ {
                if k < n {
                    add1 := s[:i]
                    add2 := s[i:j]
                    add3 := s[j:k]
                    add4 := s[k:]

                    if isValid(add1) && isValid(add2) && isValid(add3) && isValid(add4) {
                        validIP := add1 + "." + add2 + "." + add3 + "." + add4

                        validIPs = append(validIPs, validIP)
                    }
                }
            }
        }
    }

    return validIPs
}