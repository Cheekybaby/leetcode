func productExceptSelf(nums []int) []int {
    answer := make([]int, len(nums))
    for i:=0; i<len(answer); i++ {
        answer[i] = 1
    }

    product := 1

    for i := 0; i < len(nums); i++ {
        answer[i] *= product
        product *= nums[i]
    }

    product = 1

    for i := len(nums)-1; i >= 0; i-- {
        answer[i] *= product
        product *= nums[i]
    }

    fmt.Println(answer)

    return answer
}