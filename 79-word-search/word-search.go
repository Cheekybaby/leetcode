func dfs(board [][]byte, word string, cnt int, i, j int) bool {
    if cnt == len(word) {
        return true
    }
    
    if i >= len(board) || i < 0 || j >= len(board[0]) || j < 0 || word[cnt] != board[i][j] {
        return false
    }

    temp := board[i][j]
    board[i][j] = '*'

    valid := dfs(board, word, cnt+1, i + 1, j) ||
             dfs(board, word, cnt+1, i - 1, j) ||
             dfs(board, word, cnt+1, i, j + 1) ||
             dfs(board, word, cnt+1, i, j - 1)

    board[i][j] = temp

    return valid
}


func exist(board [][]byte, word string) bool {
    m, n := len(board), len(board[0])
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if board[i][j] == word[0] && dfs(board, word, 0, i, j) {
                return true
            }
        }
    }

    return false
}