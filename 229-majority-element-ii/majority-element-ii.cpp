class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for (int i=0; i<nums.size(); i+=1){
            mpp[nums[i]]+=1;
        }
        vector<int> ans;
        for (auto it:mpp){
            if (it.second > nums.size()/3){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};