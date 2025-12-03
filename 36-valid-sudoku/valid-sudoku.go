func isValidSudoku(board [][]byte) bool {
    // check all the rows
    for i := 0; i < 9; i++ {
        seen := map[byte]bool{}
        for j := 0; j < 9; j++ {
            if board[i][j] == '.' {
                continue
            }
            if _, ok := seen[board[i][j]]; ok {
                return false
            }
            seen[board[i][j]] = true
        }
    }
    // check all the columns
    for i := 0; i < 9; i++ {
        seen := map[byte]bool{}
        for j := 0; j < 9; j++ {
            if board[j][i] == '.' {
                continue
            }
            if _, ok := seen[board[j][i]]; ok {
                return false
            }
            seen[board[j][i]] = true
        }
    }
    // check all 3x3 submatrices
    for row := 0; row < 9; row += 3 {
        for col := 0; col < 9; col += 3 {
            seen := map[byte]bool{}
            for i := row; i < row + 3; i++ {
                for j := col; j < col + 3; j++ {
                    if board[i][j] == '.' {
                        continue
                    }
                    if _, ok := seen[board[i][j]]; ok {
                        return false
                    }
                    seen[board[i][j]] = true
                }
            }
        }
    }
    return true
}