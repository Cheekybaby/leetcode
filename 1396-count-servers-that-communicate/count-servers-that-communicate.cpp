class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rowCount(grid.size(), 0);
        vector<int> colCount(grid[0].size(), 0);

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == 1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == 1){
                    if (rowCount[i] > 1) ans += 1;
                    else if (colCount[j] > 1) ans += 1;
                }
            }
        }

        return ans;
    }
};