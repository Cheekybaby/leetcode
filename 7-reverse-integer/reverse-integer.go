func reverse(x int) int {
    if x <= 9 && x >= -9 {
        return x
    }
    upperBound := "2147483647"
    lowerBound := "2147483648"
    flag := false
    ans := 0
    if x < 0 {
        flag = true
        x = -1 * x
    }

    xStr := strconv.Itoa(x)
    rev := stringRev(xStr)

    if flag == true {
        if len(rev) >= len(lowerBound) && rev > upperBound {
            return 0
        } else {
            val, _ := strconv.Atoi(rev)
            ans = val
        }
    } else {
        if len(rev) >= len(upperBound) && rev > upperBound {
            return 0
        } else {
            val, _ := strconv.Atoi(rev)
            ans = val
        }
    }
    if flag {
        return -1 * ans
    } else {
        return ans
    }
}

func stringRev(xStr string) string {
    rev := ""
    for i:=len(xStr)-1; i>=0; i-- {
        rev += string(xStr[i])
    }
    i := 0
    for string(rev[i]) == "0" {
        i++
    }
    return rev[i:len(rev)]
}