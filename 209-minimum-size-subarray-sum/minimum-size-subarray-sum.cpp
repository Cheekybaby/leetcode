class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i=0, j=0, sum=0;
        while (j<nums.size()){
            sum+=nums[j];
            while (sum>=target){
                ans = min(ans, j-i+1);
                sum-=nums[i];
                i+=1;
            }
            j+=1;
        }
        if (ans == INT_MAX) return 0;
        return ans;
    }
};