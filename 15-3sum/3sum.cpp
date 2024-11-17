class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i+=1){
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = nums.size()-1;
            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    l+=1;
                    r-=1;

                    while (l<r && nums[l] == nums[l-1]) l+=1;
                    while (l<r && nums[r] == nums[r+1]) r-=1;
                } else if (sum > 0) {
                    r-=1;
                } else {
                    l+=1;
                }
            }
        }

        return ans;
    }
};