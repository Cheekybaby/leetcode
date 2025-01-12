class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        if(nums[0] == 0) return false;
        vector<int> dp(n, 0);

        for(int i=0; i<n-1; i+=1){
            if (i > 0 && dp[i] == 0) continue;
            int j = i+1;
            int x = nums[i];
            while(x>0 && j < nums.size()){
                dp[j] += 1;
                j+=1;
                x-=1;
            }
        }

        if (dp[n-1] > 0) return true;

        return false;
    }
};