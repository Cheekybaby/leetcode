func findLeastNumOfUniqueInts(arr []int, k int) int {
    set := map[int]int{}

    for i := range arr {
        set[arr[i]]++
    }
    var freq []int
    for _, f := range set {
        freq = append(freq, f)
    }

    sort.Ints(freq)
    i := 0
    for i < len(freq) {
        if freq[i] > k {
            break
        }
        k -= freq[i]
        i++
    }
    return len(freq) - i
}