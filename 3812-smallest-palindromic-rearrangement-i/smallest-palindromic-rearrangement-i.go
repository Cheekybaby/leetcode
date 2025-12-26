func smallestPalindrome(s string) string {
    lex_small := make([]byte, len(s))
    
    freq := make([]int, 26)
    for i := range s {
        freq[int(s[i] - 'a')]++
    }

    var middle byte = ' '
    i, j := 0, len(s)-1
    for idx, f := range freq {
        if f > 0 {
            char := character(idx)
            if f & 1 == 1 {
                middle = char
            }

            cnt := f/2
            for cnt > 0 {
                lex_small[i] = char
                lex_small[j] = char
                i++
                j--
                cnt--
            }
        }
    }

    if middle != ' ' {
        mid := len(lex_small)/2
        lex_small[mid] = middle
    }

    return string(lex_small)
}
func character(i int) byte {
    return byte(i + int('a'))
}