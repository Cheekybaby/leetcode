class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(), -1);
        long long sum = 0;
        int i=0, j=0, idx = k;
        while (j<nums.size()){
            sum+=nums[j];
            if (j-i+1 < 2*k+1){
                j+=1;
            } else if (j-i+1 == 2*k+1){
                int avg = sum/(2*k+1);
                ans[idx] = avg;
                idx+=1;
                j+=1;
                sum-=nums[i];
                i+=1;
            }
        }
        return ans;
    }
};