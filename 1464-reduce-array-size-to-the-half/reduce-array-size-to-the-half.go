func minSetSize(arr []int) int {
    freq := map[int]int{}
    for i := range arr {
        freq[arr[i]]++
    }

    var f []int
    for _, val := range freq {
        f = append(f, val)
    }

    sort.Ints(f)

    cnt, ele := 0, 0
    j := len(f)-1
    for ele < (len(arr)/2) {
        cnt++
        ele += f[j]
        j--
    }

    return cnt
}