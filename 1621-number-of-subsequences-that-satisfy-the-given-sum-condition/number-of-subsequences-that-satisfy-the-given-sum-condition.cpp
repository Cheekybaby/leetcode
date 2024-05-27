using ll = long long;
class Solution {
public:
    ll power(ll a, ll b, int mod){
        ll ans = 1;
        while (b!=0){
            if (b%2 == 1){
                ans = (ans*a)%mod;
            }
            a = (a*a)%mod;
            b/=2;
        }

        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size()-1;
        int ans = 0;
        const int mod = 1e9+7;

        while (i<=j){
            if (nums[i]+nums[j]>target){
                j-=1;
            } else{
                ans = (ans + (power(2, j-i, mod)))%mod;
                i+=1;
            }
        }

        return ans;
    }
};