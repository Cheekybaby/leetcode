class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int res = INT_MAX, n = nums.size();
        sort(begin(nums), end(nums));
        for(int i = 0, j = 0; i < n; i++) {
            if(i and nums[i] == nums[i-1]) continue;
            while(j < n and (long long)nums[i] * k >= (long long)nums[j]) j++;
            res = min(res, i + n - j);
        }
        return res;
    }
};