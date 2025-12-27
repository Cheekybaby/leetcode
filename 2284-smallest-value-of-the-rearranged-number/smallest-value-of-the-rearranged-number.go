func minimize(digits []int) int64 {
	var num int64

	for i := 1; i < 10; i++ {
		if digits[i] > 0 {
			num = num*10 + int64(i)
			digits[i]--
            break
		}
	}
    for digits[0] > 0 {
        num = num*10 + int64(0)
        digits[0]--
    }

    for i := 0; i < 10; i++ {
        for digits[i] > 0 {
            num = num * 10 + int64(i)
            digits[i]--
        }
    }

    return num
}

func maximize(digits []int) int64 {
	var num int64
	for i := 9; i >= 0; i-- {
		for digits[i] > 0 {
			num = num*10 + int64(i)
			digits[i]--
		}
	}

	return num
}

func smallestNumber(num int64) int64 {
	var neg bool
	if num < 0 {
		neg = true
		num *= -1
	}
	digits := make([]int, 10)
	temp := num
	for temp > 0 {
		digit := temp % 10
		digits[digit]++
		temp /= 10
	}

	// fmt.Println(digits)

	var min_val int64
	if neg {
		min_val = maximize(digits)
		min_val *= -1
	} else {
		min_val = minimize(digits)
	}

	return min_val
}