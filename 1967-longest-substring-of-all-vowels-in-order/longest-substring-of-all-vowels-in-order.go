func longestBeautifulSubstring(word string) int {
    max_len := 0
    for i := 0; i < len(word); i++ {
        if word[i] == 'a' {
            set := make(map[byte]int)
            set[word[i]]++
            j := i + 1
            for j < len(word) {
                if word[j] == word[j-1] {
                    set[word[j]]++
                } else if word[j] == 'e' {
                    if word[j-1] == 'a' {
                        set[word[j]]++
                    } else {
                        break
                    }
                } else if word[j] == 'i' {
                    if word[j-1] == 'e' {
                        set[word[j]]++
                    } else {
                        break
                    }
                } else if word[j] == 'o' {
                    if word[j-1] == 'i' {
                        set[word[j]]++
                    } else {
                        break
                    }
                } else if word[j] == 'u' {
                    if word[j-1] == 'o' {
                        set[word[j]]++
                    } else {
                        break
                    }
                } else {
                    break
                }
                j+=1
            }
            i = j-1
            if len(set) == 5 {
                length := 0
                for _, val := range set {
                    length += val
                }

                max_len = max(max_len, length)
            }
        }
    }

    return max_len
}