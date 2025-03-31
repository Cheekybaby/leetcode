func mergeAlternately(word1 string, word2 string) string {
    i, j := 0, 0
    var result string
    for i < len(word1) && j < len(word2) {
        if i <= j {
            result += string(word1[i])
            i+=1
        } else {
            result += string(word2[j])
            j+=1
        }
    }

    for i < len(word1) {
        result += string(word1[i])
        i+=1
    }
    for j < len(word2) {
        result += string(word2[j])
        j+=1
    }

    return result
}