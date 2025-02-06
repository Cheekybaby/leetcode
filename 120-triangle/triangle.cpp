class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp;
        dp = triangle[0];
        for(int i=1; i<triangle.size(); i++){
            vector<int> temp(triangle[i].size());
            for(int j=0; j<triangle[i].size(); j++){
                int left = (j-1 >= 0) ? dp[j-1] : 100000;
                int up = (j < triangle[i-1].size()) ? dp[j] : 100000;

                temp[j] = triangle[i][j] + min(left, up);
            }
            dp = temp;
        }

        int ans = 100000;
        for(int i=0; i<dp.size(); i++){
            ans = min(dp[i], ans);
        }

        return ans;
    }
};