class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> suffix(size,1);
        vector<int> prefix(size, 1);

        for (int i=1; i<size; i+=1){
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        for (int i=size-2; i>=0; i-=1){
            suffix[i] = suffix[i+1]*nums[i+1];
        }

        vector<int> ans(size);
        for (int i=0; i<size; i+=1){
            ans[i] = prefix[i]*suffix[i];
        }

        return ans;
    }
};