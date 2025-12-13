func isVowel(char byte) bool {
	if char == 'A' || char == 'a' || char == 'E' || char == 'e' || char == 'I' || char == 'i' || char == 'O' || char == 'o' || char == 'U' || char == 'u' {
		return true
	}
	return false
}

func sortVowels(s string) string {
	vowels := []int{}
	for i := range s {
		if isVowel(s[i]) {
			vowels = append(vowels, int(s[i]))
		}
	}
    sort.Ints(vowels)

    sorted := []byte(s)
    j := 0
    for i := range sorted {
        if isVowel(sorted[i]) {
            sorted[i] = byte(vowels[j])
            j++
        }
    }
    return string(sorted)
}