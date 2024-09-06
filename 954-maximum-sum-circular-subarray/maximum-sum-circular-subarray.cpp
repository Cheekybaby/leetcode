/*
- Maximum possible sum of a non-empty subarray of given array
- We create two variables for global maxima and global minima
- Also two variables for the current / local maxima and minima

- At every step we check if the current maximum is greater or the current element is greater.
- We update the gloabal maximum and minimum accordingly.
- If the global maximum is greater than zero then we know there exists atleast one positive element. So we need to check if given global maximum if greater than the sum - global minimum. Whatever is greater is the answer.
- While for negative global maximum, it is the answer as it is clear that there is no negative element in the array. 
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax = nums[0], globalMin = nums[0];
        int currMax = 0, currMin = 0;

        int sum = 0;

        for (int i=0; i<nums.size(); i+=1){
            currMax = max(currMax + nums[i], nums[i]);
            currMin = min(currMin + nums[i], nums[i]);

            sum += nums[i];

            globalMax = max(globalMax, currMax);
            globalMin = min(globalMin, currMin);
        }

        if (globalMax > 0){
            return max(globalMax, sum - globalMin);
        } 
        return globalMax;
    }
};