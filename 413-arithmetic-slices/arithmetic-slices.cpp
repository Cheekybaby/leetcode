class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size()<3){
            return 0;
        }
        int i=0, j=1;
        int ans = 0;
        while (j<nums.size()-1){
            if (nums[j]-nums[j-1] == nums[j+1]-nums[j]){
                i++;
                ans+=i;
            } else {
                i=0;
            }
            j++;
        }

        return ans;
    }
};