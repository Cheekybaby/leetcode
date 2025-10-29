func reverseWords(s string) string {
    var words []string

    i := 0
    for i < len(s) {
        for i < len(s) && s[i] == ' ' {
            i++
        }

        if i == len(s) {
            break
        }

        j := i

        for j < len(s) && s[j] != ' ' {
            j++
        }

        str := s[i:j]

        words = append(words, str)

        i = j
    }

    var ans string

    for i := len(words)-1; i >= 0; i-- {
        ans += words[i]

        if i > 0 {
            ans += " "
        }
    }

    return ans
}