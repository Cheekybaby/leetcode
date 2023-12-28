class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int mod = 1e9+7;
        sort(nums.begin(), nums.end());

        vector<int> power(nums.size()+1, 1);

        for (int i=1; i<=nums.size(); i+=1){
            power[i] = (power[i-1]<<1)%mod;
        }

        int left = 0, right = nums.size()-1;
        int ans = 0;
        while (left<=right){
            if (nums[left]+nums[right]<=target){
                ans = (ans + power[right-left])%mod;
                left+=1;
            } else {
                right-=1;
            }
        }

        return ans;
    }
};