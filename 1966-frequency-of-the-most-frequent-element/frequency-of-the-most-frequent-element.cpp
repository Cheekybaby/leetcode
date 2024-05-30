using ll = long long;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i=0, j=0;
        ll sum=0, ans=0;

        while (j<nums.size()){
            sum+=nums[j];
            ll winlen = j-i+1;
            while (nums[j]*winlen > sum+k){
                sum-=nums[i];
                i+=1;
                winlen = j-i+1;
            }
            ans = max(ans, winlen);
            j+=1;
        }

        return ans;
    }
};