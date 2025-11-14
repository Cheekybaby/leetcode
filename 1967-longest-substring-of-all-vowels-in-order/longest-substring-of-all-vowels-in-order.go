func longestBeautifulSubstring(word string) int {
    cnt, length := 1, 1
    max_len := 0

    for i := 0; i < len(word)-1; i++ {
        if word[i+1] == word[i] {
            length++
        } else if word[i+1] > word[i] {
            cnt++
            length++
        } else {
            cnt = 1
            length = 1
        }

        if cnt == 5 {
            max_len = max(max_len, length)
        }
    }

    return max_len
}