func discountPrices(sentence string, discount int) string {
    words := strings.Split(sentence, " ")
	for i := 0; i < len(words); i++ {
		word := words[i]
		if word[0] == '$' {
			if isValid(word[1:]) {
				number, _ := strconv.Atoi(word[1:])
				discounted := (float64(number)) - (float64(number) * (float64(discount) / 100))
				final := strconv.FormatFloat(discounted, 'f', 2, 64)
				words[i] = "$" + final
			}
		}
	}
    sentence = strings.Join(words, " ")

	return sentence
}
func isValid(word string) bool {
    if len(word) == 0 {
        return false
    }
	for i := range word {
		if word[i] > '9' || word[i] < '0' {
			return false
		}
	}
	return true
}