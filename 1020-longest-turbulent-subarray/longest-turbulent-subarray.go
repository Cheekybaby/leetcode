func maxTurbulenceSize(arr []int) int {
    if len(arr) == 1 { return 1 }
    
    max_len := 0
    up, down := 1, 1
    for i := 1; i < len(arr); i++ {
        if arr[i] > arr[i-1] {
            up = down + 1
            down = 1
        } else if arr[i] < arr[i-1] {
            down = up + 1
            up = 1
        } else {
            up, down = 1, 1
        }

        if up > max_len {
            max_len = up
        }
        if down > max_len {
            max_len = down
        }
    }

    return max_len
}