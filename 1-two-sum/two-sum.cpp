class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hashing
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i+=1){
            mpp[nums[i]] = i;
        }

        for (int i=0; i<nums.size(); i+=1){
            int tofind = target-nums[i];
            if(mpp.find(tofind) != mpp.end() && mpp[tofind] != i){
                return {i, mpp[tofind]};
            }
        }

        return {-1,-1};
    }
};