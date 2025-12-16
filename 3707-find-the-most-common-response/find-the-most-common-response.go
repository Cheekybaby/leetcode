func findCommonResponse(responses [][]string) string {
    set := map[string]int{}

    for _, day := range responses {
        temp := map[string]int{}
        for _, res := range day {
            temp[res]++
        }

        for key, _ := range temp {
            set[key]++
        }
    }

    var res string
    max_freq := 0

    for key, val := range set {
        if val > max_freq {
            max_freq = val
            res = key
        } else if val == max_freq && (key == "" || key < res) {
            res = key
        }
    }

    return res
}