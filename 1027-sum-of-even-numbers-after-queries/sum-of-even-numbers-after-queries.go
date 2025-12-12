func sumEvenAfterQueries(nums []int, queries [][]int) []int {
    sum := 0
    for _, num := range nums {
        if num & 1 == 0 {
            sum += num
        }
    }

    even := make([]int, len(queries))

    for i, q := range queries {
        idx := q[1]
        val := q[0]

        if nums[idx] & 1 == 0 {
            sum -= nums[idx]
        }

        nums[idx] += val

        if nums[idx] & 1 == 0 {
            sum += nums[idx]
        }

        even[i] = sum
    }

    return even
}