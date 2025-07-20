class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int global_max = nums[0], global_min = nums[0];
        int curr_max = 0, curr_min = 0;

        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            curr_max = max(curr_max+nums[i], nums[i]);
            curr_min = min(curr_min+nums[i], nums[i]);

            sum += nums[i];

            global_max = max(global_max, curr_max);
            global_min = min(global_min, curr_min);
        }

        if (global_max > 0){
            return max(global_max, sum - global_min);
        }
        return global_max;
    }
};