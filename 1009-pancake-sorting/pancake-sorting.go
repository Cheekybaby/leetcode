func pancakeSort(arr []int) []int {
    var flipidx []int
    sorted := make([]int, len(arr))
    copy(sorted, arr)

    sort.Ints(sorted)

    num := len(arr)

    for compare(arr, sorted) != true {
        // we will do the pancake flips
        // First flip the largest (for now) at the start of the index
        large_idx := 0
        for i := range arr {
            if arr[i] == num {
                large_idx = i
                break
            }
        }

        if large_idx != 0 {
            flipidx = append(flipidx, large_idx+1)
            reverse(arr, 0, large_idx)
        }
        // now flip it
        reverse(arr, 0, num-1)
        flipidx = append(flipidx, num)

        num -= 1
    }

    return flipidx
}

func reverse(arr []int, st, end int) {
    for st < end {
        arr[st], arr[end] = arr[end], arr[st]
        st++
        end--
    }
}

func compare(arr, nums []int) bool {
    for i := range arr {
        if arr[i] != nums[i] {
            return false
        }
    }
    return true
}