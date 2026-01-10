func maxTurbulenceSize(arr []int) int {
    if len(arr) == 1 { return 1 }

    flag := make([]int, len(arr))
    flag[0] = 0

    for i := 1; i < len(arr); i++ {
        if arr[i] > arr[i-1] { 
            flag[i] = 1 
        } else if arr[i] == arr[i-1] { 
            flag[i] = 0 
        } else { 
            flag[i] = -1
        }
    }

    var max_len int

    for i := 0; i < len(flag); {
        j := i + 1
        for j < len(flag) {
            if flag[j] == flag[j-1] || flag[j] == 0 {
                break
            }
            j++
        }

        length := j - i
        max_len = max(max_len, length)

        for j < len(flag) && flag[j] == 0 {
            j++
        }

        if j >= len(flag) { break }

        i = j - 1
        flag[i] = 0
    }

    return max_len
}