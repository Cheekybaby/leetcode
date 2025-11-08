func numSpecialEquivGroups(words []string) int {
    groups := make(map[string]bool)

    for i := range words {
        word := []byte(words[i])
        sortstr(word)
        groups[string(word)] = true
    }

    return len(groups)
}

func sortstr(word []byte) {
    for i := 0; i < len(word); i+=2 {
        for j := i+2; j < len(word); j+=2 {
            if word[i] > word[j] {
                word[i], word[j] = word[j], word[i]
            }
        }
    }

    for i := 1; i < len(word); i+=2 {
        for j := i+2; j < len(word); j+=2 {
            if word[i] > word[j] {
                word[i], word[j] = word[j], word[i]
            }
        }
    }
}