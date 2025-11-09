func solve(piles []int, i, j, turn, alice, bob int, dp [][][]int) bool {
    if j <= i {
        if alice > bob {
            return true
        }
        return false
    }

    if dp[i][j][turn%2] != -1 {
        return (dp[i][j][turn % 2] == 1)
    }

    var first, second bool

    if turn % 2 == 0 {
        // bob takes a turn
        first = solve(piles, i+1, j, turn+1, alice, bob + piles[i], dp)
        second = solve(piles, i, j-1, turn+1, alice, bob + piles[j], dp)
    } else {
        // alice takes a turn
        first = solve(piles, i+1, j, turn+1, alice + piles[i], bob, dp)
        second = solve(piles, i, j-1, turn+1, alice + piles[j], bob, dp)
    }

    val := first || second

    if val {
        dp[i][j][turn%2] = 1
    } else {
        dp[i][j][turn%2] = 0
    }

    return (dp[i][j][turn%2] == 1)
}

func stoneGame(piles []int) bool {
    dp := initDP(len(piles))
    alice := solve(piles, 0, len(piles)-1, 1, 0, 0, dp)
    return alice
}
func initDP(n int) (dp [][][]int) {
    dp = make([][][]int, n)
    for i := range dp {
        dp[i] = make([][]int, n)
        for j := range dp[i] {
            dp[i][j] = make([]int, 2)
            for k := range dp[i][j] {
                dp[i][j][k] = -1
            }
        }
    }

    return dp
}