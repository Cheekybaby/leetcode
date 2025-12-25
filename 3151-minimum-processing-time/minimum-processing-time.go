func minProcessingTime(processorTime []int, tasks []int) int {
    sort.Ints(processorTime)
    sort.Ints(tasks)
    ans := 0
    j := 0
    for i := len(tasks)-1; i >= 0; i -= 4 {
        processor := processorTime[j]
        task := []int{tasks[i], tasks[i-1], tasks[i-2], tasks[i-3]}
        ans = max(ans, processor + maxEle(task))
        j++
    }

    return ans
}
func maxEle(nums []int) int {
    ele := nums[0]
    for i := range nums {
        if nums[i] > ele {
            ele = nums[i]
        }
    }
    return ele
}