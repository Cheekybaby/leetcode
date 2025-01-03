class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n+1, 0);
        for (int i=0; i<n; i+=1){
            pref[i+1] = pref[i] + (long long)nums[i];
        }
        int ans = 0;
        for(int i = 0; i < n-1; i+=1){
            long long left = pref[i+1];
            long long right = pref[n] - pref[i+1];
            if (left >= right){
                ans += 1;
            }
        }
        return ans;
    }
};