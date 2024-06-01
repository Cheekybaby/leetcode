class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i=0; i<nums.size(); i+=1){
            nums[i]*=nums[i];
        }

        sort(nums.begin(), nums.end());

        return nums;
    }
};