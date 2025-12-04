func minSubArrayLen(target int, nums []int) int {
	sum := 0
	max_len := math.MaxInt
	i := 0
	for j := 0; j < len(nums); j++ {
		sum += nums[j]

		for sum >= target {
			len := j - i + 1
			max_len = min(max_len, len)
			sum -= nums[i]
			i++
		}
	}

	if max_len == math.MaxInt {
		return 0
	}

	return max_len
}