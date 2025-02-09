class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            m[i-nums[i]]++;
        }
        for(auto &it:m){
            int x = n - it.second;
            ans += (it.second * x);
            n-=it.second;
        }

        return ans;
    }
};