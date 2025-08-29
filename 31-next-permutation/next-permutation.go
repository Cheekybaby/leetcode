func reverse(nums []int, l, r int) {
	for l < r {
		nums[l], nums[r] = nums[r], nums[l]
		l++
		r--
	}
}

func nextPermutation(nums []int) {
	idx := len(nums) - 2

	for idx >= 0 {
		if nums[idx] < nums[idx+1] {
			break
		}
		idx--
	}

	if idx != -1 {
		mini_idx, mini := idx, math.MaxInt
		for i := idx + 1; i < len(nums); i++ {
			if nums[i] > nums[idx] {
				if nums[i] <= mini {
					mini = nums[i]
					mini_idx = i
				}
			}
		}

		nums[idx], nums[mini_idx] = nums[mini_idx], nums[idx]
	}

	reverse(nums, idx+1, len(nums)-1)
}