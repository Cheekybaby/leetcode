func groupAnagrams(strs []string) [][]string {
    groupMap := make(map[string][]string)
    for i := range strs {
        str := strs[i]
        temp := stringSort(str)
        groupMap[temp] = append(groupMap[temp], str)
    }

    var groups [][]string
    for i := range groupMap {
        val, ok := groupMap[i]
        if ok {
            groups = append(groups, val)
        }
    }
    return groups
}

func stringSort(s string) (t string) {
    runes := []rune(s)

    sort.Slice(runes, func(i, j int) bool {
        return runes[i] < runes[j]
    })

    t = string(runes)
    return t
}