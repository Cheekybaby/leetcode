func canReach(arr []int, start int) bool {
    n := len(arr)
    var dfs func(int)bool
    dfs = func (idx int) bool {
        if idx >= n || idx < 0 || arr[idx] < 0 {
            return false
        }
        if arr[idx] == 0 {
            return true
        }

        left := idx - arr[idx]
        right := idx + arr[idx]

        arr[idx] = -arr[idx]

        return dfs(left) || dfs(right)
    }

    return dfs(start)
}