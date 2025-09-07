func sortedSquares(nums []int) []int {
    i, j, k := 0, len(nums)-1, len(nums)-1
    square := make([]int, len(nums))

    for i <= j {
        x := (nums[i]*nums[i])
        y := (nums[j]*nums[j])

        if x >= y {
            square[k] = x
            i++
        } else {
            square[k] = y
            j--
        }
        k--
    }

    return square
}