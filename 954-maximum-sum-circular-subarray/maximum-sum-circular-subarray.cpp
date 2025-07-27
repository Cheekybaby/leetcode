class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax = nums[0], globalMin = nums[0];
        int currMax = 0, currMin = 0;
        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            currMax = max(currMax + nums[i], nums[i]);
            currMin = min(currMin + nums[i], nums[i]);

            sum += nums[i];

            globalMax = max(globalMax, currMax);
            globalMin = min(globalMin, currMin);
        }

        if (globalMax > 0){
            return max(globalMax, sum-globalMin);
        }
        return globalMax;
    }
};