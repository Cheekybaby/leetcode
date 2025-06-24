class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, len = 0;
        for(int j=0; j<nums.size(); j++){
            if (nums[j] - nums[i] == 1){
                len = max(len, (j-i+1));
            }
            while (nums[j] - nums[i] > 1) {
                i++;
            }
        }
        return len;
    }
};