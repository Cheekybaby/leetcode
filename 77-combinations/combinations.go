func solve(array []int, idx, k int, temp []int, ans *[][]int) {
    if len(temp) == k {
        tmp := make([]int, k)
        copy(tmp, temp)
        *ans = append(*ans, tmp)

        return 
    }

    if idx >= len(array) {
        return 
    }

    temp = append(temp, array[idx])
    solve(array, idx+1, k, temp, ans)
    temp = temp[:len(temp)-1]
    solve(array, idx+1, k, temp, ans)
}

func combine(n int, k int) [][]int {
    var temp []int
    var ans [][]int
    array := make([]int, n)
    for i := range array {
        array[i] = i+1
    }
    
    solve(array, 0, k, temp, &ans)

    return ans
}