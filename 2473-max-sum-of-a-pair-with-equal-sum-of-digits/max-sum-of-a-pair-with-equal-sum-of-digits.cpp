class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<long long>> m;
        for(int i=0; i<nums.size(); i++){
            int x = nums[i];
            int sum = 0;
            while(x > 0){
                sum += x%10;
                x/=10;
            }
            m[sum].push_back(nums[i]);
        }

        for(auto &it:m){
            sort(it.second.rbegin(), it.second.rend());
        }
        long long ans = -1;
        for(auto &it:m){
            vector<long long> x = it.second;
            if (x.size() > 1)
                ans = max(ans, x[0] + x[1]);
        }
        return ans;
    }
};