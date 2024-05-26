class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0, j=0, ans = INT_MAX;
        while (j<nums.size()){
            while (j-i+1!=k) j+=1;
            ans = min(ans, nums[j]-nums[i]);
            i+=1;
            j+=1;
        }

        return ans;
    }
};