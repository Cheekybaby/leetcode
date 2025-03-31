func mergeAlternately(word1 string, word2 string) string {
    rune1, rune2 := []rune(word1), []rune(word2)
    result := make([]rune, len(word1) + len(word2))

    n := 0
    if len(word1) < len(word2) {
        n = len(word1)
    } else {
        n = len(word2)
    }

    i, j := 0, 0
    for i = 0; i<n; i++ {
        result[j] = rune1[i]
        result[j+1] = rune2[i]
        j+=2
    }

    for i < len(word1) {
        result[j] = rune1[i]
        i+=1
        j+=1
    }

    for i < len(word2) {
        result[j] = rune2[i]
        i+=1
        j+=1
    }

    return string(result)
}