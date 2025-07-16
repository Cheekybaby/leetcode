class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0, j=0;
        unordered_set<int> check;
        while(j < nums.size()){
            int len = j-i;
            if (len <= k){
                if (check.count(nums[j])){
                    return true;
                }
                check.insert(nums[j]);
                j+=1;
            } else {
                check.erase(nums[i]);
                i++;
            }
        }
        return false;
    }
};