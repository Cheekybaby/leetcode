class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for (int i=0; i<nums.size(); i+=1){
            if (mpp.count(nums[i])){
                int diff = abs(mpp[nums[i]] - i);
                if (diff <= k){
                    return true;
                }
            }
            mpp[nums[i]] = i;
        }

        return false;
    }
};