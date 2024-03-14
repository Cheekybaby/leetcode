class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0, count = 0, ans = 0;
        for (int  j=0; j<nums.size(); j+=1){
            if (nums[j] == 1){
                goal-=1;
                count = 0;
            }

            while (goal == 0  && i<=j){
                goal+=nums[i];
                i+=1;
                count+=1;
                if (i>j-goal+1){
                    break;
                }
            }

            while (goal<0){
                goal+=nums[i];
                i+=1;
            }

            ans += count;
        }

        return ans;
    }
};