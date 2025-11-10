func areSentencesSimilar(sentence1 string, sentence2 string) bool {
    if len(sentence1) < len(sentence2) {
        sentence1, sentence2 = sentence2, sentence1
    }
    var words1, words2 []string

    i := 0
    for j := 0; j < len(sentence1); j++ {
        if sentence1[j] == ' ' {
            str := sentence1[i:j]
            words1 = append(words1, str)
            i = j + 1
        } else if j == len(sentence1)-1 {
            str := sentence1[i:j+1]
            words1 = append(words1, str)
        }
    }
    i = 0
    for j := 0; j < len(sentence2); j++ {
        if sentence2[j] == ' ' {
            str := sentence2[i:j]
            words2 = append(words2, str)
            i = j + 1
        } else if j == len(sentence2)-1 {
            str := sentence2[i:j+1]
            words2 = append(words2, str)
        }
    }
    fmt.Println(words1)
    fmt.Println(words2)

    st, e1, e2 := 0, len(words1)-1, len(words2)-1

    for st < len(words1) && st < len(words2) {
        if words1[st] != words2[st] {
            break
        }
        st++
    }

    for e1 >= 0 && e2 >= 0 {
        if words1[e1] != words2[e2] {
            break
        }
        e1--
        e2--
    }

    return (e2 < st)
}

func findIdx(str string, words []string) int {
    for i := range words {
        if words[i] == str {
            return i
        }
    }
    return -1
}