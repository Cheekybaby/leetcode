func sortedSquares(nums []int) []int {
    i, k := 0, 0
    ans := make([]int, len(nums), len(nums))
    for i < len(nums) {
        if nums[i] >= 0 {
            break;
        }
        i++
    }
    j := i-1
    for j >= 0 && i < len(nums) {
        left := nums[j] * nums[j]
        right := nums[i] * nums[i]

        if left <= right {
            ans[k] = left
            j-=1
        } else {
            ans[k] = right
            i+=1
        }
        k+=1
    }

    for j >= 0 {
        ans[k] = nums[j] * nums[j]
        k+=1
        j-=1
    }
    for i < len(nums) {
        ans[k] = nums[i] * nums[i]
        i+=1
        k+=1
    }
    return ans
}