class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans;
        sort(nums.begin(),nums.end());
        vector<int> v;
        for(int i=0; i<=nums.size(); i++){
            v.push_back(i);
        }

        for(int i=0; i<v.size()-1; i++){
            if(nums[i]!=v[i]){
                ans = v[i];
                return ans;
            }
        }
        ans = v.back();
        return ans;
    }
};