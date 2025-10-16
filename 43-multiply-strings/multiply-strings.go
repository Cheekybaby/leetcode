func mul(x int, s string) (prod string) {
    carry := 0
    for i := len(s)-1; i >= 0; i-- {
        y := int(s[i] - '0')

        p := (x * y) + carry
        carry = p / 10
        val := p % 10
        prod += strconv.Itoa(val)
    }

    if carry > 0 {
        prod += strconv.Itoa(carry)
    }

    prod = reverse(prod)

    return prod
}

func updateProd(prev string, next string) string {
    var sum string
    carry := 0
    i, j := len(prev)-1, len(next)-1
    for i >= 0 || j >= 0 {
        op1 := getVal(prev, i)
        op2 := getVal(next, j)

        add := op1 + op2 + carry
        
        carry = add / 10
        val := add % 10

        sum += strconv.Itoa(val)
        i--
        j--
    }

    if carry > 0 {
        sum += strconv.Itoa(carry)
    }

    sum = reverse(sum)

    return sum
}

func removeLeadingZeros(s string) string {
    idx := 0
    for idx < len(s) {
        if s[idx] != '0' {
            break
        }
        idx++
    }

    if idx == len(s) {
        return "0"
    }
    return s[idx:]
}

func multiply(num1 string, num2 string) string {
    var tot_prod string
    zero := 0
    for i := len(num1)-1; i >= 0; i-- {
        val := int(num1[i] - '0')
        // Multiply it with num2
        prod := mul(val, num2)
        
        // Take care of the trailing zeros
        for j := 0; j < zero; j++ {
            prod += "0"
        }
        zero++

        // whatever we get will be added to running sum
        tot_prod = updateProd(tot_prod, prod)
    }

    // Remove all the leading zeros
    tot_prod = removeLeadingZeros(tot_prod)

    // return the running sum
    return tot_prod
}
func reverse(s string) string {
    r := []rune(s)
    i, j := 0, len(r)-1
    for i < j {
        r[i], r[j] = r[j], r[i]
        i++
        j--
    }

    return string(r)
}
func getVal(s string, idx int) int {
    if idx < 0 {
        return 0
    }

    val := int(s[idx] - '0')
    return val
}