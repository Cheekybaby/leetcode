class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero = 0, one = 0;
        int ans = 0;
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i+=1){
            if (nums[i] == 0){
                zero+=1;
            } else {
                one+=1;
            }
            if (mpp.find(one-zero) == mpp.end()){
                mpp.insert({(one-zero), i});
            }
            if (one == zero){
                ans = one+zero;
            } else {
                int idx = mpp[(one-zero)];
                ans = max(ans, i-idx);
            }
        }

        return ans;
    }
};