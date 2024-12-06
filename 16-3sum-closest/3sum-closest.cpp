class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];

        for (int i=0; i<nums.size(); i+=1){
            int l = i+1, r = nums.size()-1;

            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == target) return target;
                else if (abs(sum-target) < abs(target - ans)) {
                    ans = sum;
                }
                else if (sum < target) l+=1;
                else if (sum > target) r-=1;
            }
        }

        return ans;
    }
};