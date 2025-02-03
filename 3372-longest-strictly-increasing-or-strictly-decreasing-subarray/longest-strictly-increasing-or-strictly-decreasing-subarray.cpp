class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len = 1;
        for(int i=0; i<nums.size()-1;){
            int j = i;
            while(i < nums.size()-1 && nums[i] < nums[i+1]){
                i++;
            }
            len = max(len, i-j+1);
            i++;
        }

        for(int i=0; i<nums.size()-1;){
            int j = i;
            while(i < nums.size()-1 && nums[i] > nums[i+1]){
                i++;
            }
            len = max(len, i-j+1);
            i++;
        }

        return len;
    }
};