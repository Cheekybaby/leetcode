func groupAnagrams(strs []string) [][]string {
    group := make(map[string][]string)

    for i := range strs {
        str := []byte(strs[i])

        sort.Slice(str, func (i, j int) bool {
            return str[i] < str[j]
        })

        group[string(str)] = append(group[string(str)], strs[i])
    }

    var ans [][]string
    for _, val := range group {
        ans = append(ans, val)
    }

    return ans
}