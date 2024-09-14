class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;
        int i = 0, j = 0;
        while (j < nums.size()-1){
            if (nums[j+1] <= nums[j]){
                i = j + 1;
            }
            ans = max(ans, j-i+1);
            j+=1;
        }
        return ans + 1;
    }
};