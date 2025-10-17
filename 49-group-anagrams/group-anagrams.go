func groupAnagrams(strs []string) [][]string {
    set := make(map[string][]string)
    for i := range strs {
        str := strs[i]
        r := []rune(str)
        sort.Slice(r, func(i, j int) bool {
            return r[i] < r[j]
        })
        str = string(r)
        set[str] = append(set[str], strs[i])
    }

    var groups [][]string
    for _, val := range set {
        groups = append(groups, val)
    }

    return groups
}