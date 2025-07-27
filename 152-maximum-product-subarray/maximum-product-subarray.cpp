class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_overall = nums[0];
        int max_curr = nums[0];
        int min_curr = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(max_curr, min_curr);
            }
            max_curr = max(nums[i], max_curr * nums[i]);
            min_curr = min(nums[i], min_curr * nums[i]);

            max_overall = max(max_overall, max_curr);
        }

        return max_overall;
    }
};