class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0, j=0; 
        int ans = 0;
        while (j<nums.size()){
            if (nums[j] != 1){
                j+=1;
                continue;
            }
            i = j;
            int len = 0;
            while (j<nums.size() && nums[j] == 1){
                len = max(len, j-i+1);
                j+=1;
            }
            ans = max(len, ans);
        }

        return ans;
    }
};