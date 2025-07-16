#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> quads;
        for(int i=0; i<nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int a = nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int b = nums[j];
                int l = j+1, r = nums.size()-1;
                while (l < r){
                    int c = nums[l], d = nums[r];
                    ll sum = (ll)a + (ll)b + (ll)c + (ll)d;
                    
                    if (sum == target){
                        quads.push_back({a, b, c, d});
                        l++;
                        r--;

                        while(l < r && nums[l] == nums[l-1]) l++;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    } else if (sum > target){
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return quads;
    }
};