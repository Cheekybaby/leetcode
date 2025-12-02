// Divide
func divideAndMerge(nums []int, left, right int) {
    if left >= right {
        return
    }

    mid := left + (right - left)/2

    divideAndMerge(nums, mid+1, right)
    divideAndMerge(nums, left, mid)

    merge(nums, left, mid, right)
}

// Merge
func merge(nums []int, left, mid, right int) {
    l, r := mid - left + 1, right - mid
    l_arr, r_arr := make([]int, l), make([]int, r)

    for i := 0; i < l; i++ {
        l_arr[i] = nums[left + i]
    }
    for i := 0; i < r; i++ {
        r_arr[i] = nums[mid + 1 + i]
    }

    i, j, k := 0, 0, left
    for i < l && j < r {
        if l_arr[i] <= r_arr[j] {
            nums[k] = l_arr[i]
            i++
        } else {
            nums[k] = r_arr[j]
            j++
        }
        k++
    }

    for i < l {
        nums[k] = l_arr[i]
        i++
        k++
    }
    for j < r {
        nums[k] = r_arr[j]
        j++
        k++
    }
}

func sortArray(nums []int) []int {
    divideAndMerge(nums, 0, len(nums)-1)

    return nums
}