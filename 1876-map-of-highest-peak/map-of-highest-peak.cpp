class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int> (m, 100000));

        for(int i=0; i<n; i+=1){
            for(int j=0; j<m; j+=1){
                if (isWater[i][j] == 1){
                    ans[i][j] = 0;
                }
            }
        }

        for(int i=0; i<n; i+=1){
            for(int j=0; j<m; j+=1){
                if (i > 0){
                    ans[i][j] = min(ans[i][j], ans[i-1][j] + 1);
                }
                if (j > 0){
                    ans[i][j] = min(ans[i][j], ans[i][j-1] + 1);
                }
            }
        }

        for(int i=n-1; i>=0; i-=1){
            for(int j=m-1; j>=0; j-=1){
                if (i < n-1){
                    ans[i][j] = min(ans[i][j], ans[i+1][j] + 1);
                }
                if (j < m-1){
                    ans[i][j] = min(ans[i][j], ans[i][j+1] + 1);
                }
            }
        }
        return ans;
    }
};