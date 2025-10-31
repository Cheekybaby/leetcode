func maxIncreasingSubarrays(nums []int) int {
    cnt, precnt, k := 1, 0, 0

    for i := 1; i < len(nums); i++ {
        if nums[i] > nums[i-1] {
            cnt++
        } else {
            precnt = cnt
            cnt = 1
        }

        k = max(k, min(precnt, cnt))
        k = max(k, cnt/2)
    }

    return k
}