class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long sum = 0;
        sort(nums.begin(), nums.end());
        int i=0, j = nums.size()-1;
        while (i < j-1){
            long long c = nums[j-1];
            sum += c;
            i+=1;
            j-=2;
        }

        return sum;
    }
};