class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        dp.push_back(triangle[0]);
        for(int i=1; i<triangle.size(); i++){
            vector<int> temp(triangle[i].size());
            for(int j=0; j<triangle[i].size(); j++){
                int left = (j-1 >= 0) ? dp[i-1][j-1] : 100000;
                int up = (j < triangle[i-1].size()) ? dp[i-1][j] : 100000;

                temp[j] = triangle[i][j] + min(left, up);
            }
            dp.push_back(temp);
        }

        int ans = 100000;
        for(int i=0; i<dp[dp.size()-1].size(); i++){
            ans = min(dp[dp.size()-1][i], ans);
        }

        return ans;
    }
};