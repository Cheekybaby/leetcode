func printVertically(s string) []string {
    words := strings.Split(s, " ")
    max_len := 0
    for _, word := range words {
        if len(word) > max_len {
            max_len = len(word)
        }
    }

    vertical_words := []string{}
    for i := 0; i < max_len; i++ {
        vert := []byte{}
        for _, word := range words {
            var char byte
            if i >= len(word) {
                char = ' '
            } else {
                char = word[i]
            }
            vert = append(vert, char)
        }
        for j := len(vert)-1; j >= 0; j-- {
            if vert[j] != ' ' {
                vert = vert[:j+1]
                break
            }
        }
        vertical_words = append(vertical_words, string(vert))
    }

    return vertical_words
}