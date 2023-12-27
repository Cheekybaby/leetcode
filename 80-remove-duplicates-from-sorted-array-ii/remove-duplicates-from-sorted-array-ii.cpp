class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0, i=0;
        while (i<nums.size()){
            if (j==0 || j==1 || nums[j-2]!=nums[i]){
                nums[j] = nums[i];
                j+=1;
            }
            i+=1;
        }

        return j;
    }
};