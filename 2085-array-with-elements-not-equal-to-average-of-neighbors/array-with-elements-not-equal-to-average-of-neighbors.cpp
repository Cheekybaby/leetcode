class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 1;
        while (i<nums.size()-1){
            if ((nums[i]>nums[i-1] && nums[i]<nums[i+1]) || (nums[i]<nums[i-1] && nums[i]>nums[i+1])){
                swap(nums[i], nums[i+1]);
            }
            i+=1;
        }

        return nums;
    }
};