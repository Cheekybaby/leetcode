class Solution {
public:
    void bfs(vector<vector<char>> &board, int i, int j){
        // Four connected nodes are up, down, left, and right
        // I need to make something that tells me if the node is already visited or not.

        // Handle out of bounds
        if(i < 0 || i>board.size()-1) return ;
        if(j < 0 || j>board[0].size()-1) return ;
        if(board[i][j] == '1' || board[i][j] == 'X') return ;
        board[i][j] = '1';

        bfs(board, i+1, j);
        bfs(board, i-1, j);
        bfs(board, i, j-1);
        bfs(board, i, j+1);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // First Row
        for(int i=0; i<n; i++){
            if(board[0][i] == 'O'){
                bfs(board, 0, i);
            }
        }
        // Last Row
        for(int i=0; i<n; i++){
            if(board[m-1][i] == 'O'){
                bfs(board, m-1, i);
            }
        }
        // First Col
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O'){
                bfs(board, i, 0);
            }
        }
        // Last Col
        for(int i=0; i<m; i++){
            if(board[i][n-1] == 'O'){
                bfs(board, i, n-1);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '1'){
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};