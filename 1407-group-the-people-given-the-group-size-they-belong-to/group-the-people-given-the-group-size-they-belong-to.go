func groupThePeople(groupSizes []int) [][]int {
    groups := map[int][]int{}

    var ans [][]int

    for i := range groupSizes {
        key := groupSizes[i]
        val := i

        groups[key] = append(groups[key], val)

        if len(groups[key]) == key {
            ans = append(ans, groups[key])
            groups[key] = []int{}
        }
    }

    return ans
}