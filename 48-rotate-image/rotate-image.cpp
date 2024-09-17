class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose
        for (int i=0; i<matrix.size(); i+=1){
            for (int j=0; j<=i; j+=1){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reverse each row
        for (int i=0; i<matrix.size(); i+=1){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};