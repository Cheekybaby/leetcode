func generateStrings(n int, idx int, str []byte, ans *[]string) {
	if idx == n {
		tmp := make([]byte, n)
		copy(tmp, str)

		*ans = append(*ans, string(tmp))

		return
	}

	if idx == 0 {
		str[idx] = '0'
		generateStrings(n, idx+1, str, ans)
		str[idx] = '1'
		generateStrings(n, idx+1, str, ans)
	} else {
		if str[idx-1] == '1' {
			str[idx] = '0'
			generateStrings(n, idx+1, str, ans)
		}
		str[idx] = '1'
		generateStrings(n, idx+1, str, ans)
	}
}

func validStrings(n int) []string {
	str := make([]byte, n)
	ans := []string{}

	generateStrings(n, 0, str, &ans)

	return ans
}