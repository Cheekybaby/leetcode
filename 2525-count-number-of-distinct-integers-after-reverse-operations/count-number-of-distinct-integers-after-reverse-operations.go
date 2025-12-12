func reverse(num int) int {
    x := 0
    for num > 0 {
        digit := num % 10
        x = x * 10 + digit
        num /= 10
    }

    return x
}

func countDistinctIntegers(nums []int) int {
    set := map[int]int{}

    for _, num := range nums {
        rev := reverse(num)

        set[rev]++
        set[num]++
    }

    return len(set)
}