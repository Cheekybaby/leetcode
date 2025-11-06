func isZeroArray(nums []int, queries [][]int) bool {
    prefix := make([]int, len(nums)+1)

    for _, query := range queries {
        left := query[0]
        right := query[1]

        prefix[left]+=1
        prefix[right+1]-=1
    }

    curr_op := 0
    operations := make([]int, len(nums)+1)
    for i := range prefix {
        curr_op += prefix[i]

        operations[i] = curr_op
    }

    for i := range nums {
        if operations[i] < nums[i] {
            return false
        }
    }
    return true
}