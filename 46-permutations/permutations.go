func factorial(n int) int {
	fact := 1
	for i := 1; i <= n; i++ {
		fact *= i
	}

	return fact
}

func nextPermutation(nums []int) []int {
	n := len(nums)
	idx := n - 2
	for idx >= 0 {
		if nums[idx] < nums[idx+1] {
			break
		}
		idx--
	}

	if idx != -1 {
		mini_idx, mini := idx, math.MaxInt
		for i := idx + 1; i < n; i++ {
			if nums[i] > nums[idx] {
				if nums[i] <= mini {
					mini_idx = i
					mini = nums[i]
				}
			}
		}

		nums[idx], nums[mini_idx] = nums[mini_idx], nums[idx]
	}

	reverse(nums, idx+1, n-1)

	return nums
}

func permute(nums []int) [][]int {
	sort.Ints(nums)
	n := factorial(len(nums))

	permutations := make([][]int, n)

	permutations[0] = append([]int(nil), nums...)
	for i := 1; i < n; i++ {
		perm := append([]int(nil), permutations[i-1]...)
		nxt := nextPermutation(perm)

		permutations[i] = append([]int(nil), nxt...)
	}

	return permutations
}

func reverse(nums []int, i, j int) {
	for i < j {
		nums[i], nums[j] = nums[j], nums[i]
		i++
		j--
	}
}