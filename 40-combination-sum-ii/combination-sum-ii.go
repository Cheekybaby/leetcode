func solve(cand []int, target, sum, idx int, temp *[]int, ans *[][]int) {
    if sum == target {
        sol := make([]int, len(*temp))
        copy(sol, *temp)
        *ans = append(*ans, sol)
        return
    }
    
    if sum > target || idx >= len(cand) {
        return 
    }

    for i := idx; i < len(cand); i++ {
        if i > idx && cand[i] == cand[i-1] {
            continue
        }

        if sum + cand[i] > target {
            continue
        }

        *temp = append(*temp, cand[i])
        solve(cand, target, sum + cand[i], i+1, temp, ans)
        *temp = (*temp)[:len(*temp)-1]
    }
}

func combinationSum2(candidates []int, target int) [][]int {
    var temp []int
    var ans [][]int
    sort.Ints(candidates)
    solve(candidates, target, 0, 0, &temp, &ans)
    return ans
}