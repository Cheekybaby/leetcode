func helper(log string) (key string, value string, isDigit bool) {
    isDigit = false
    for i := range log{
        if log[i] == ' ' {
            key = log[ : i]
            value = log[i + 1 : ]
            break
        }
    }

    if value[0] <= '9' && value[0] >= '0' { isDigit = true }

    return key, value, isDigit
}

func reorderLogFiles(logs []string) []string {
    let_val, dig_val := []string{}, []string{}
    group := map[string][]string{}
	for _, log := range logs {
		key, value, isDigit := helper(log)

		if isDigit {
			dig_val = append(dig_val, log)
		} else {
			let_val = append(let_val, value)
            group[value] = append(group[value], key)
		}
	}

    for _, val := range group {
        sort.Strings(val)
    }

	sort.Strings(let_val)

	ans := []string{}
    for _, log := range let_val {
        var str string

        keys := group[log]
        key := keys[0]
        group[log] = keys[1:]

        str = key + " " + log

        ans = append(ans, str)
    }

    for _, log := range dig_val {
        ans = append(ans, log)
    }

	return ans
}