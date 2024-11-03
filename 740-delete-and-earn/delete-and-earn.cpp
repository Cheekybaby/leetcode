class Solution {
public:
    int solve(vector<int> &nums, int index, vector<int> &memo){
        if (index >= nums.size()) return 0;
        if (memo[index] != -1) return memo[index];

        int i = index;
        int sum = 0;
        while(i < nums.size() && nums[i] == nums[index]){
            sum += nums[i];
            i+=1;
        }
        while (i < nums.size() && (nums[i] == nums[index]+1)){
            i+=1;
        }
        int take = sum + solve(nums, i, memo);
        int not_take = solve(nums, index+1, memo);

        return memo[index] = max(take, not_take);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), -1);

        return solve(nums,0, dp);
    }
};