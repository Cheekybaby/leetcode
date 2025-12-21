func getStrongest(arr []int, k int) []int {
    sort.Ints(arr)

    center := (len(arr) - 1)/2
    m := arr[center]

    strength := [][2]int{}

    for i := range arr {
        st := abs(arr[i] - m)
        strength = append(strength, [2]int{st, arr[i]})
    }
    
    sort.Slice(strength, func (i, j int) bool {
        if strength[i][0] == strength[j][0] {
            return strength[i][1] > strength[j][1]
        }
        return strength[i][0] > strength[j][0]
    })

    strongest := make([]int, k)
    for i := 0; i < k; i++ {
        strongest[i] = strength[i][1]
    }

    return strongest
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}