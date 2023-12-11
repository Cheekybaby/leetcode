class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums2(2*n);
        for (int i=0; i<n; i++){
            nums2[i] = nums[i];
            nums2[i+n] = nums[i];
        }

        return nums2;
    }
};