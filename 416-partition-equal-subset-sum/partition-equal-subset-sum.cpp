class Solution {
public:
    bool solve(vector<int> &nums, int target, int index, int curr_sum, vector<vector<int>> &memo){
        if (index == nums.size()) return 0;
        if (curr_sum == target) return 1;
        if (curr_sum > target) return 0;
        if (memo[index][curr_sum] != -1) return memo[index][curr_sum];

        bool take = solve(nums, target, index + 1, curr_sum + nums[index], memo);
        bool not_take = solve(nums, target, index + 1, curr_sum, memo);

        memo[index][curr_sum] = (take || not_take);
        return memo[index][curr_sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto x:nums){
            sum+=x;
        }

        if (sum % 2 == 1){
            return false;
        }
        vector<vector<int>> memo (nums.size(), vector<int> (20005, -1));
        return solve(nums, sum/2, 0, 0, memo);
    }
};