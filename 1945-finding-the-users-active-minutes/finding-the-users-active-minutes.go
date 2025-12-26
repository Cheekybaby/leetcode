func findingUsersActiveMinutes(logs [][]int, k int) []int {
    uam := make([]int, k)
    user_map := map[int][]int{}

    for i := 0; i < len(logs); i++ {
        user := logs[i][0]
        timestamp := logs[i][1]

        user_map[user] = append(user_map[user], timestamp)
    }

    for _, val := range user_map {
        set := map[int]bool{}
        for i := range val {
            set[val[i]] = true
        }
        uam[len(set) - 1]++
    }

    return uam
}