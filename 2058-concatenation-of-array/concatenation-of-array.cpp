class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums2(2*n);
        int i = 0;
        for (auto it:nums){
            nums2[i] = nums[i];
            nums2[i+n] = nums[i];
            i++;
        }

        return nums2;
    }
};