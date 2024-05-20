class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i=0; i<nums.size();  i+=1){
            mpp[nums[i]]+=1;
        }
        int n = nums.size()/2;
        for (auto it:mpp){
            if (it.second>n){
                return it.first;
            }
        }

        return -1;
    }
};