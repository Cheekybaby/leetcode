class Solution {
public:
    int solve(vector<int> &nums, int n, vector<int> &memo){
        if (n < 0) return 0;
        if (n == 0) return nums[0];
        if (memo[n] != -1) return memo[n];

        int picked = nums[n] + solve(nums, n - 2, memo);
        int notPicked = solve(nums, n - 1, memo);

        memo[n] = max(picked, notPicked);
        return memo[n];
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(nums, nums.size()-1, memo);
    }
};