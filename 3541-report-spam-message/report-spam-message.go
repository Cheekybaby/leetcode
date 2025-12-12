func reportSpam(message []string, bannedWords []string) bool {
    set := map[string]bool{}

    for _, bw := range bannedWords {
        set[bw] = true
    }

    cnt := 0

    for _, mess := range message {
        if _, ok := set[mess]; ok {
            cnt++
        }
    }

    return (cnt >= 2)
}