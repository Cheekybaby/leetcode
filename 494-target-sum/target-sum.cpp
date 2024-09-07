class Solution {
public:
    int solve(vector<int> &nums, int target, int index, int ans, vector<vector<int>> &memo, int offset){
        if (index == nums.size()) {
            return ans == target ? 1 : 0;
        }
        if (memo[index][ans+offset] != -1) return memo[index][ans+offset];
        int add = solve(nums, target, index + 1, ans + nums[index], memo, offset);
        int sub = solve(nums, target, index + 1, ans - nums[index], memo, offset);

        memo[index][ans + offset] = add + sub;
        return memo[index][ans+offset];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> memo(nums.size(), vector<int> (2*sum + 1, -1));
        return solve(nums, target, 0, 0, memo, sum);
    }
};