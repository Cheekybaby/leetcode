class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int votes = 0;
        for (int i=0; i<nums.size(); i+=1){
            if (votes == 0){
                candidate = nums[i];
            }
            if (nums[i] == candidate){
                votes+=1;
            } else if (nums[i] != candidate){
                votes -= 1;    
            }
        }
        int count = 0;
        for (int i=0; i<nums.size(); i+=1){
            if (nums[i] == candidate){
                count += 1;
            }
        }

        if (count > nums.size()/2){
            return candidate;
        }
        return -8;
    }
};