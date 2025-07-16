class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> quads;
        set<vector<int>> st;
        for(int i=0; i<nums.size(); i++){
            int a = nums[i];
            for(int j=i+1; j<nums.size(); j++){
                int b = nums[j];
                int l = j+1, r = nums.size()-1;
                while (l < r){
                    int c = nums[l], d = nums[r];
                    long long sum = (long long)a + (long long)b + (long long)c + (long long)d;
                    
                    if (sum == target){
                        st.insert({a, b, c, d});
                        l++;
                        r--;
                    } else if (sum > target){
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        for(auto &it:st){
            quads.push_back(it);
        }
        return quads;
    }
};