class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        bool flag = true;
        int row = grid.size(), col = grid[0].size();
        
        for (int i=0; i<row; i+=1){
            for (int j=0; j<col; j+=1){
                if (j!=col-1 && grid[i][j] == grid[i][j+1]){
                    return false;
                }
                if (i!=row-1 && grid[i][j] != grid[i+1][j]){
                    return false;
                }
            }
        }
        
        return true;
    }
};