func longestCommonPrefix(strs []string) string {
    l_pref := []byte(strs[0])
    for i := 1; i < len(strs); i++ {
        str := []byte(strs[i])
        j := 0
        for ; j < min(len(str), len(l_pref)); j++ {
            if str[j] != l_pref[j] {
                break
            }
        }

        l_pref = str[:j]
    }

    return string(l_pref)
}