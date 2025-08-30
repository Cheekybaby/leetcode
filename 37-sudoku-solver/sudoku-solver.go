func solveSudoku(board [][]byte)  {
    solve(board)
}

func solve(board [][]byte) bool {
    for i := range board {
        for j := range board[i] {
            if board[i][j] == '.' {
                // Now we try
                for c := '1'; c <= '9'; c++ {
                    if isValid(board, i, j, byte(c)) {
                        board[i][j] = byte(c)

                        if solve(board) {
                            return true
                        } else  {
                            board[i][j] = '.'
                        }
                    }
                }
                return false
            }
        }
    }
    return true
}

func isValid(board [][]byte, r, c int, char byte) bool {
    for i := 0; i < 9; i++ {
        if board[r][i] == char {
            return false
        }
        if board[i][c] == char {
            return false
        }
        if board[3 * (r / 3) + i / 3][3 * (c /3) + i % 3] == char {
            return false
        }
    }
    return true
}