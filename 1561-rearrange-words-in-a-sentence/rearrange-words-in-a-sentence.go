func arrangeWords(text string) string {
    words := []string{}
    max_len := 0
    for i := 0; i < len(text); {
        j := i
        word := []byte{}
        for j < len(text) && text[j] != ' ' {
            word = append(word, text[j])
            j++
        }

        words = append(words, string(word))
        max_len = max(max_len, len(word))

        i = j+1
    }

    word_groups := make([][]string, max_len+1)

    for _, word := range words {
        word_groups[len(word)] = append(word_groups[len(word)], word)
    }

    words = []string{}
    for i := 1; i <= max_len; i++ {
        if len(word_groups[i]) > 0 {
            for _, word := range word_groups[i] {
                words = append(words, word)
            }
        }
    }

    for i := range words {
        word := []byte(words[i])
        if i == 0 {
            if word[0] > 'Z' {
                char := word[0]
                new_char := byte(int(char) - 32)
                word[0] = new_char
            }
        } else {
            if words[i][0] <= 'Z' {
                char := word[0]
                new_char := byte(int(char) + 32)
                word[0] = new_char
            }
        }
        words[i] = string(word)
    }

    var rearranged string
    for i := range words {
        if i == len(words)-1 {
            rearranged += words[i]
        } else {
            rearranged += (words[i] + " ")
        }
    }
    return rearranged
}