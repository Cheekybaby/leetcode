class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        sort(nums.begin(),nums.end());
        for(i; i<nums.size(); i++){
            if(nums[i]!=i){
                break;
            }
        }
        return i;
    }
};