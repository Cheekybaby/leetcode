func myAtoi(s string) int {
	n := len(s)
	i := 0
	for i < n && s[i] == ' ' {
		i++
	}
	if i == n {
		return 0
	}
	flag := false
	if s[i] == '-' {
		flag = true
		i++
	} else if s[i] == '+' {
		i++
	}
	var ans string
	for i < n {
		if isValid(s[i]) {
			ans += string(s[i])
			i++
		} else {
			break
		}
	}
	if len(ans) == 0 {
		return 0
	}
    idx := 0
	for idx = range ans {
		if ans[idx] != '0' {
			break
		}
	}

	number := ans[idx:]
    if len(number) == 0 {
        return 0
    }
    if len(number) >= 11 {
        if flag {
            return math.MinInt32
        }
        return math.MaxInt32
    }

    var op int 
    for j := range number {
        op = op * 10 + int(number[j] - '0')
    }

    if flag {
        op *= -1
    }

    if op > math.MaxInt32 {
        return math.MaxInt32
    } else if op < math.MinInt32 {
        return math.MinInt32
    }

    return op
}
func isValid(char byte) bool {
	if char <= '9' && char >= '0' {
		return true
	}
	return false
}