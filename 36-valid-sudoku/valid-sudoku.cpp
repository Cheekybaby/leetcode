class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;
        // Checking all the rows
        for (int i=0; i<9; i+=1){
            unordered_set<char> st;
            for (int j=0; j<9; j+=1){
                if (board[i][j] == '.') continue;
                else if (st.count(board[i][j]) != 0) return false;
                st.insert(board[i][j]);
            }
        }

        // Checking all the Columns
        for(int i=0; i<9; i+=1){
            unordered_set<char> st;
            for (int j=0; j<9; j+=1){
                if (board[j][i] == '.') continue;
                else if (st.count(board[j][i]) != 0) return false;
                st.insert(board[j][i]);
            }
        }

        // Checking every 3X3 sub-boxes
        for (int i=0; i<9; i+=3){
            for (int j=0; j<9; j+=3){
                unordered_set<int> st;
                for(int x=i; x<i+3; x+=1){
                    for(int y=j; y<j+3; y+=1){
                        if (board[x][y] == '.') continue;
                        else if (st.find(board[x][y]) != 0) return false;
                        st.insert(board[x][y]);
                    }
                }
            }
        }

        return ans;
    }
};