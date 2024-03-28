class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0,  j=0;
        int count = 0;
        unordered_map<int,int> mpp;
        while (j<nums.size()){
            mpp[nums[j]]++;

            if (mpp[nums[j]] > k){
                while (nums[i]!=nums[j]){
                    mpp[nums[i]]--;
                    i++;
                }
                mpp[nums[i]]--;
                i++;
            }

            count = max(count, j-i+1);
            j+=1;
        }

        return count;
    }
};