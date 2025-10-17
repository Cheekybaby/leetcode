func generateMatrix(n int) [][]int {
    ans := make([][]int, n)
    for i := range ans {
        ans[i] = make([]int, n)
    }

    cnt := 1
    left, right := 0, n-1
    top, bottom := 0, n-1

    for left <= right && top <= bottom {
        // top
        for i := left; i <= right; i++ {
            ans[top][i] = cnt
            cnt++
        }
        top++
        // right
        for i := top; i <= bottom; i++ {
            ans[i][right] = cnt
            cnt++
        }
        right--
        // bottom
        if left <= right {
            for i := right; i >= left; i-- {
                ans[bottom][i] = cnt
                cnt++
            }
            bottom--
        }
        // left
        if top <= bottom {
            for i := bottom; i >= top; i-- {
                ans[i][left] = cnt
                cnt++
            }
            left++
        }
    }

    return ans
}