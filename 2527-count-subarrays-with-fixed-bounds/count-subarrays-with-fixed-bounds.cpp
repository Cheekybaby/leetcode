class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int outofrange = -1, leftidex = -1, rightidex = -1;

        for (int i=0; i<nums.size(); i+=1){
            if (!(minK<=nums[i] && maxK>=nums[i])){
                outofrange = i;
            }
            if (nums[i] == minK){
                leftidex = i;
            }
            if (nums[i] == maxK){
                rightidex = i;
            }

            ans += max(0, min(leftidex, rightidex) - outofrange);
        }

        return ans;
    }
};