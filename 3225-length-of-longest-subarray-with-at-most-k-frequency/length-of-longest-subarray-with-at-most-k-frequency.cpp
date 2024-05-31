class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0, j=0;
        int ans = 0;
        unordered_map<int,int> mpp;
        while (j<nums.size()){
            mpp[nums[j]]+=1;

            while (mpp[nums[j]]>k){
                mpp[nums[i]]-=1;
                i+=1;
            }

            ans = max(ans, j-i+1);

            j+=1;
        }

        return ans;
    }
};