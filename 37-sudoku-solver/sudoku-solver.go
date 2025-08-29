func solveSudoku(board [][]byte)  {
    solve(board)
}

func solve(board [][]byte) bool {
    // We will find an empty space
    for i:=0; i<len(board); i++ {
        for j:=0; j<len(board[i]); j++ {
            if board[i][j] == '.' { // An empty cell
                // Let's try out filling everything from 1 to 9
                for v := '1'; v <= '9'; v++ {
                    // Check if the current state of board is going to be valid or not
                    if isValid(board, i, j, byte(v)) == true {
                         board[i][j] = byte(v)
                        // If this is valid, then we will simply go for the next
                        if solve(board) == true {
                            return true
                        } else {
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

func isValid(board [][]byte, r int, c int, char byte) bool {
    for i := 0; i < 9; i++ {
        // Ckeck if the row is good or not
        if board[r][i] == char {
            return false
        }
        // Check if the column is good or not
        if board[i][c] == char {
            return false
        }
        // Check if the submatrix is good or not
        if board[3 * (r / 3) + i /3][3 * (c / 3) + i % 3] == char {
            return false
        }
    }
    return true
}