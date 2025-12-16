func findLonely(nums []int) []int {
    set := map[int]int{}
    var lonely []int
    for _, num := range nums {
        set[num]++
    }

    for key, val := range set {
        _, ok1 := set[key-1]
        _, ok2 := set[key+1]

        if !ok1 && !ok2 && val == 1 {
            lonely = append(lonely, key)
        }
    }

    return lonely
}