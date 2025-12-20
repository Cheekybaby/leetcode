func sumOfDigits(num int) int {
    sum := 0
    for num > 0 {
        sum += (num%10)
        num/=10
    }

    return sum
}

func maximumSum(nums []int) int {
    sort.Ints(nums)
    poss_pair := map[int][]int{}
    for i := range nums {
        key := sumOfDigits(nums[i])
        poss_pair[key] = append(poss_pair[key], nums[i])
    }
    max_sum := -1
    for _, val := range poss_pair {
        if len(val) > 1 {
            p1 := val[len(val)-1]
            p2 := val[len(val)-2]
            sum := p1 + p2

            max_sum = max(max_sum, sum)
        }
    }

    return max_sum
}