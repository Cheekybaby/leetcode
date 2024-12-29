class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<m; i+=1){
            for(int j=1; j<n; j+=1){
                if(grid[j][i] <= grid[j-1][i]){
                    ans += ((grid[j-1][i] - grid[j][i]) + 1);
                    grid[j][i] = grid[j-1][i] + 1;
                }
            }
        }

        return ans;
    }
};