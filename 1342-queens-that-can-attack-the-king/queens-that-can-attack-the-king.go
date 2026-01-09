var dir = [][]int{ {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1} }

func queensAttacktheKing(queens [][]int, king []int) [][]int {
    chessboard := make([][]int, 8)
    for i := range chessboard {
        chessboard[i] = make([]int, 8)
    }

    for _, q := range queens {
        qx, qy := q[0], q[1]
        chessboard[qx][qy] = 1
    }

    attack := [][]int{}
    for _, d := range dir {
        dx, dy := d[0], d[1]
        x, y := king[0], king[1]
        
        for x >= 0 && x < 8 && y >= 0 && y < 8 {
            x_next, y_next := x + dx, y + dy
            if x_next >= 0 && x_next < 8 && y_next >= 0 && y_next < 8 && chessboard[x_next][y_next] == 1 {
                attack = append(attack, []int{x_next, y_next})
                break
            }
            x = x_next
            y = y_next

        }
    }

    return attack
}