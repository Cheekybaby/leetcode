class Solution {
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!binary_search(nums.begin(), nums.end(), target)) return {-1,-1}; // Element isn't present
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin(); // First Occurance
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin(); // Last Occurance
        return {l, r-1};
    }
};