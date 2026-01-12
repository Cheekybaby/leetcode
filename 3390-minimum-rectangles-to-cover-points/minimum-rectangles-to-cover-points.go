func upperBound(nums []int, target int) int {
    left, right := 0, len(nums)-1
    for left <= right {
        mid := left + (right - left)/2

        if nums[mid] <= target {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }

    return left
}

func minRectanglesToCoverPoints(points [][]int, w int) int {
    distinct := map[int]bool{}
    for _, p := range points {
        distinct[p[0]] = true
    }

    indices := []int{}
    for key, _ := range distinct {
        indices = append(indices, key)
    }

    sort.Ints(indices)

    rectangle := 0
    i := 0
    for i < len(indices) {
        x1 := indices[i]
        x2 := w + x1

        j := upperBound(indices, x2)

        rectangle++
        i = j
    }

    return rectangle
}