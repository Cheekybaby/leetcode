class NumMatrix {
private: 
    vector<vector<int>> prefix; // Prefix sum 
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix = matrix;

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                int l = (j-1 < 0) ? 0 : prefix[i][j-1];
                int u = (i-1 < 0) ? 0 : prefix[i-1][j];
                int d = (j-1 >=0 && i-1 >=0) ? prefix[i-1][j-1] : 0;

                prefix[i][j] += (l + u);
                prefix[i][j] -= d;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int y = prefix[row2][col2];
        int a = (row1-1 < 0)? 0 : prefix[row1-1][col2];
        int b = (col1-1 < 0) ? 0 : prefix[row2][col1-1];
        int c = (row1-1 < 0 || col1-1 < 0) ? 0 : prefix[row1-1][col1-1];
        return y - (a + b - c);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */