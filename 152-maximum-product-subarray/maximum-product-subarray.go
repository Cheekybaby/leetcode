func maxProduct(nums []int) int {
    ans, product := math.MinInt64, 1

    for i:=0; i<len(nums); i++ {
        product *= nums[i]
        ans = max(product, ans)
        if product == 0 {
            product = 1
        }
    }
    product = 1
    for i:=len(nums)-1; i>=0; i-- {
        product *= nums[i]
        ans = max(product, ans)
        if product == 0 {
            product = 1
        }
    }

    return ans
}