func resultsArray(nums []int, k int) []int {
	power := make([]int, len(nums)-k+1)
	for i := range power {
		power[i] = -1
	}
	i, j := 0, 1
	for j < len(nums) {
		if (nums[j] - 1) == nums[j-1] {
			j++
            continue
		}
		win_len := j - i

		for win_len >= k {
			power[i] = nums[i+k-1]
			i++
			win_len = j - i
		}
		i = j
		j++
	}

	win_len := j - i
	for win_len >= k {
		power[i] = nums[i+k-1]
		i++
		win_len = j - i
	}

	return power
}