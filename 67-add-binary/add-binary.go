func addBinary(a string, b string) string {
    i, j := len(a)-1, len(b)-1
    carry := false

    n := max(len(a), len(b))
    sum := make([]byte, n+1)
    for k := range sum {
        sum[k] = '0'
    }

    pos := n
    for i >= 0 || j >= 0 {
        op1 := (i >= 0 && a[i] == '1')
        op2 := (j >= 0 && b[j] == '1')

        if op1 && op2 {
            if carry {
                sum[pos] = '1'
            }
            carry = true
        } else {
            if op1 != op2 {
                if carry {
                    carry = true
                } else {
                    sum[pos] = '1'
                }
            } else {
                if carry {
                    sum[pos] = '1'
                    carry = false
                }
            }
        }

        i--
        j--
        pos--
    }

    if carry {
        sum[0] = '1'
        return string(sum)
    }
    return string(sum[1:])
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
