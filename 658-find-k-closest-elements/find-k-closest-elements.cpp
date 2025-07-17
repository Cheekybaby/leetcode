class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int i = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
        vector<int> ans;
        int j = i-1;
        while ((j >= 0 || i < nums.size()) && k > 0){
            int a = (j >= 0) ? abs(nums[j] - x) : INT_MAX;
            int b = (i < nums.size()) ? abs(nums[i] - x): INT_MAX;
            
            bool diff = false;
            
            if (a != INT_MAX && b != INT_MAX){
                if (a <= b) {
                    ans.push_back(nums[j]);
                    j-=1;
                } else {
                    ans.push_back(nums[i]);
                    i+=1;
                }
                k-=1;
            } else if (a == INT_MAX){
                ans.push_back(nums[i]);
                i+=1;
                k-=1;
            } else {
                ans.push_back(nums[j]);
                j-=1;
                k-=1;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};