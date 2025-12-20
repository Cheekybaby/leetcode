func compressedString(word string) string {
	comp := []byte{}
	char := word[0]
	cnt := 1
	for i := 1; i < len(word); i++ {
        if cnt == 9 {
			comp = append(comp, '9')
			comp = append(comp, char)
			cnt = 0
		}

        if word[i] == char {
			cnt++
		} else {
            if cnt > 0 {
                comp = append(comp, byte(cnt+int('0')))
                comp = append(comp, char)
            }
			char = word[i]
			cnt = 1
		}
	}

	comp = append(comp, byte(cnt+int('0')))
	comp = append(comp, char)

	return string(comp)
}