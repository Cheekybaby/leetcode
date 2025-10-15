func solve(candidates []int, target, sum, idx int, temp *[]int, ans *[][]int) {
	if sum == target {
        sol := make([]int, len(*temp))
        copy(sol, *temp)
		*ans = append(*ans, sol)
		return
	}
	if sum > target || idx >= len(candidates) {
		return
	}
	*temp = append(*temp, candidates[idx])
	solve(candidates, target, sum+candidates[idx], idx, temp, ans)
	*temp = (*temp)[:len(*temp)-1]
	solve(candidates, target, sum, idx+1, temp, ans)
}

func combinationSum(candidates []int, target int) [][]int {
	var temp []int
	var ans [][]int
	solve(candidates, target, 0, 0, &temp, &ans)
	return ans
}