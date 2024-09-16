class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> coord;

        for (int i=0; i<matrix.size(); i+=1){
            for (int j=0; j<matrix[0].size(); j+=1){
                if (matrix[i][j] == 0){
                    coord.push_back({i,j});
                }
            }
        }

        for (int i=0; i<coord.size(); i+=1){
            int r = coord[i][0];
            int c = coord[i][1];

            for (int j=0; j<matrix[0].size(); j+=1){
                matrix[r][j] = 0;
            }
            for (int j=0; j<matrix.size(); j+=1){
                matrix[j][c] = 0;
            }
        }
    }
};