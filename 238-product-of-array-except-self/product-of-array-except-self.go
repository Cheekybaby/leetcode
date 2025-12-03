func productExceptSelf(nums []int) []int {
    prod := make([]int, len(nums))
    product := 1
    for i := range nums {
        prod[i] = product
        product *= nums[i]
    }

    product = 1
    for i := len(nums)-1; i >= 0; i-- {
        prod[i] *= product
        product *= nums[i]
    }

    return prod
}