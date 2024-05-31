using ll = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxele = 0;
        for (int i=0; i<nums.size(); i+=1){
            maxele = max(nums[i], maxele);
        }
        
        ll ans = 0, count = 0;
        int i=0, j=0;
        while (j<nums.size()){
            if (nums[j] == maxele){
                count+=1;
            }
            while (count == k){
                if (nums[i] == maxele){
                    count-=1;
                }
                i+=1;
            }

            ans+=i;
            j+=1;
        }

        return ans;
    }
};