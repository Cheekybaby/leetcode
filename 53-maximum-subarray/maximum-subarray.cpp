class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0;
        int max_sum = INT_MIN;

        for (int i=0; i<nums.size(); i+=1){
            current_sum = max(current_sum + nums[i], nums[i]);


            // if (current_sum < 0){
            //     current_sum = 0;
            // }

            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};