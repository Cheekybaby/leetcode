class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix;
        prefix[0] = 1;
        int sum = 0, cnt = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if (prefix.count(sum - k)){
                cnt += prefix[sum-k];
            }
            prefix[sum]++;
        }
        return cnt;
    }
};