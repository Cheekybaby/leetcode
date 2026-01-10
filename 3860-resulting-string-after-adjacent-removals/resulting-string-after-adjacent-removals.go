func resultingString(s string) string {
	var st []byte
	i := 0
	for i = 0; i < len(s); i++ {
		char := s[i]

		if len(st) > 0 {
			top := st[len(st)-1]

			diff := getDiff(char, top)

			if diff == 1 {
				st = st[:len(st)-1]
			} else {
				st = append(st, char)
			}
		} else {
			st = append(st, s[i])
		}
	}

	return string(st)
}

func getDiff(char, top byte) int {
    diff := abs(int(char) - int(top))
    if (char == 'z' && top == 'a') || (char == 'a' && top == 'z') { diff = 1 }

    return diff
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}