#define ll unsigned long long int
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n;
        sort(nums.begin(), nums.end());
        for(auto &it:nums) cout << it << " ";
        for(int i=0; i<n; i++){
            int curr_val = nums[i];
            ll max_possible = (ll)curr_val * k;
            if (max_possible >= nums[n-1]){
                // Everything is included from here onwards, and since the array is sorted, we don't need to go any further with out iteration.
                int remove = i;
                ans = min(ans, remove);
                break;
            }
            int j = upper_bound(nums.begin(), nums.end(), max_possible) - nums.begin();
            int remove = n - (j - i);
            ans = min(ans, remove);
        }

        return ans;
    }
};