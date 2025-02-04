class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int sum = nums[0];
        for(int i=0; i<n-1;){
            int temp = nums[i];
            while(i < n-1 && nums[i] < nums[i+1]){
                temp += nums[i+1];
                i++;
            }
            i++;
            sum = max(sum, temp);
        }

        return sum;
    }
};