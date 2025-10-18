func searchMatrix(matrix [][]int, target int) bool {
    m, n := len(matrix), len(matrix[0])
    // first find the correct row to look for target
    i, j := 0, m-1
    for i <= j {
        mid := i + (j - i)/2

        if matrix[mid][n-1] == target {
            return true
        } else if matrix[mid][n-1] > target {
            j = mid - 1
        } else {
            i = mid + 1
        }
    }
    
    if i > m-1 {
        return false
    }
    // find target in that row
    l, r := 0, n-1
    for l <= r {
        mid := l + (r - l)/2

        if matrix[i][mid] == target {
            return true
        } else if matrix[i][mid] > target {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }

    return false
}
func binarySearch(array []int, target int) int {
    i, j := 0, len(array)-1
    for i < j {
        mid := i + (j - i)/2

        if array[mid] == target {
            return mid
        } else if array[mid] > target {
            j = mid - 1
        } else {
            i = mid + 1
        }
    }
    return i
}