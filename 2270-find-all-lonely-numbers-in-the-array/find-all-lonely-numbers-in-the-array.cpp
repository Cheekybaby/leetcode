class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        if (nums.size() < 2){
            return nums;
        }
        if (nums[0]!=nums[1] && nums[0]+1!=nums[1]){
            ans.push_back(nums[0]);
        }
        for (int i=1; i<nums.size()-1; i+=1){
            if ((nums[i]-1 != nums[i-1]) && (nums[i]+1 != nums[i+1]) && (nums[i] != nums[i-1]) && (nums[i] != nums[i+1])){
                ans.push_back(nums[i]);
            }
        }
        if (nums[nums.size()-1] != nums[nums.size()-2] && nums[nums.size()-1] != nums[nums.size()-2] +1){
            ans.push_back(nums[nums.size()-1]);
        }

        return ans;
    }
};