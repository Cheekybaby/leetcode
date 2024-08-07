class Solution {
public:
    int solve(vector<int> &nums, int index, vector<int> &memo){
        if (index == 0) return nums[0];
        if (index < 0) return 0;
        if (memo[index] != -1) return memo[index];
        int robs = nums[index] + solve(nums, index - 2, memo);
        int not_robs = solve(nums, index - 1, memo);

        memo[index] = max(robs, not_robs);
        return memo[index];
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(nums, nums.size()-1, memo);
    }
};