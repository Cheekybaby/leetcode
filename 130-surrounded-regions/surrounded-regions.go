func bfs(board [][]byte, i, j int) {
    if i < 0 || i >= len(board) {
        return 
    }
    if j < 0 || j >= len(board[0]) {
        return
    }

    if board[i][j] == '1' || board[i][j] == 'X' {
        return
    }

    board[i][j] = '1'

    bfs(board, i+1, j)
    bfs(board, i-1, j)
    bfs(board, i, j+1)
    bfs(board, i, j-1)
}

func solve(board [][]byte)  {
    m, n := len(board), len(board[0])

    // First row
    for i := 0; i < n; i++ {
        if board[0][i] == 'O' {
            bfs(board, 0, i)
        }
    }

    // Last row
    for i := 0; i < n; i++ {
        if board[m-1][i] == 'O' {
            bfs(board, m-1, i)
        }
    }

    // First col
    for i := 0; i < m; i++ {
        if board[i][0] == 'O' {
            bfs(board, i, 0)
        }
    }

    // Last col
    for i := 0; i < m; i++ {
        if board[i][n-1] == 'O' {
            bfs(board, i, n-1)
        }
    }


    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if board[i][j] == '1' {
                board[i][j] = 'O'
            } else {
                board[i][j] = 'X'
            }
        }
    }
}