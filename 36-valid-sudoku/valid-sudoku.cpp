class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check for valid rows
        for(int i=0; i<9; i++){
            unordered_set<int> st;
            for(int j=0; j<9; j++){
                if (board[i][j] <= '9' && board[i][j] > '0'){
                    int x = board[i][j] - '0';
                    if (st.count(x)) return false;
                    st.insert(x);
                }
            }
        }
        // Check for valid cols
        for(int i=0; i<9; i++){
            unordered_set<int> st;
            for(int j=0; j<9; j++){
                if (board[j][i] <= '9' && board[j][i] > '0'){
                    int x = board[j][i] - '0';
                    if (st.count(x)) return false;
                    st.insert(x);
                }
            }
        }
        // Check for those 3x3 squares
        for(int l=0; l<9; l+=3){
            for(int k=0; k<9; k+=3){
                unordered_set<int> st;
                for(int i=l; i<3+l; i++){
                    for(int j=k; j<3+k; j++){
                        if (board[i][j] <= '9' && board[i][j] > '0'){
                            int x = board[i][j] - '0';
                            if (st.count(x)) return false;
                            st.insert(x);
                        }
                    }
                }
            }
        }
        return true;
    }
};