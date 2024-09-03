class Solution {
public:
    int solve(vector<int> &nums, int index, int rem, vector<vector<int>> &memo){
        if (index >= nums.size()){
            if (rem == 0) return 0;
            return INT_MIN;
        }
        if (memo[index][rem] != -1) return memo[index][rem];

        int sum = nums[index] + solve(nums, index + 1, (rem + nums[index])%3, memo);
        int not_sum = solve(nums, index + 1, rem, memo);

        memo[index][rem] = max(sum, not_sum);
        return memo[index][rem];
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int> (3, -1));
        return solve(nums, 0, 0, memo);
    }
};