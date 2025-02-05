class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        vector<int> acc(20000);
        for(int i=0; i<nums.size();){
            int sum = nums[i];
            int index = nums[i];
            i++;
            while(i < nums.size() && nums[i] == nums[i-1]){
                sum += nums[i];
                i++;
            }

            acc[index] = sum;
        }

        ans = maximumSum(acc);

        return ans;
    }

private:
    int maximumSum(vector<int> &acc){
        vector<int> dp(acc.size()+1, -1);
        return solve(acc, 0, dp);
    }
    int solve(vector<int> &acc, int index, vector<int> &dp){
        if (index >= acc.size()) return 0;

        if (dp[index] != -1) return dp[index];

        int take = acc[index] + solve(acc, index+2, dp);
        int not_take = solve(acc, index+1, dp);

        return dp[index] = max(take, not_take);
    }
};