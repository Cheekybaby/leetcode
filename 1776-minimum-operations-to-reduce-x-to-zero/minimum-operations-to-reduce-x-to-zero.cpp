using ll = long long;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        ll sum = 0;
        for (int i=0; i<nums.size(); i+=1){
            sum+=nums[i];
        }
        if (sum < x){
            return -1;
        } else if (sum == x){
            return nums.size();
        }
        ll target = sum - ll(x);

        int i=0, j=0, ans = nums.size();
        sum = 0;
        while (j<nums.size()){
            sum+=nums[j];
            while (sum > target){
                sum-=nums[i];
                i+=1;
            }
            if (sum == target){
                int len = nums.size() - (j-i+1);
                ans = min(ans, len);
            }
            j+=1;
        }
        if (ans == nums.size()) return -1;
        return ans;
    }
};