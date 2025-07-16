class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen = INT_MAX;
        int i=0, j=0;
        int sum = 0;
        while (j < nums.size()){
            sum += nums[j];
            if (sum >= target){
                while(i <= j && sum >= target){
                    minlen = min(minlen, j-i+1);
                    sum-=nums[i];
                    i++;
                }
            }
            j++;
        }
        return (minlen == INT_MAX) ? 0 : minlen;
    }
};