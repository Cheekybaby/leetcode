class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        long long last = INT_MIN;
        for (auto &it:nums){
            long long x = max((long long)(it - k), last + 1);
            if (x <= (long long)(it + k)){
                ans += 1;
                last = x;
            }
        }

        return ans;
    }
};