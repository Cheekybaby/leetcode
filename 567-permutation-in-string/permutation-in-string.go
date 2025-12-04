func areSame(hash, window [26]int) bool {
    for i := 0; i < 26; i++ {
        if hash[i] != window[i] {
            return false
        }
    }

    return true
}

func checkInclusion(s1 string, s2 string) bool {
    if len(s2) < len(s1) {
        return false
    }

    hash, window := [26]int{}, [26]int{}

    for i := 0; i < len(s1); i++ {
        hash[int(s1[i] - 'a')]++
        window[int(s2[i] - 'a')]++
    }

    if areSame(hash, window) {
        return true
    }

    for i := len(s1); i < len(s2); i++ {
        window[int(s2[i] - 'a')]++
        window[int(s2[i-len(s1)] -'a')]--

        if areSame(hash, window) {
            return true
        }
    }

    return false
}