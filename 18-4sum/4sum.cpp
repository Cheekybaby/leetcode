#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        if (nums.size() < 4) return {};
        for (int i=0; i<nums.size()-3; i+=1){
            for (int j=i+1; j<nums.size()-2; j+=1){
                ll toFind = (ll)target - (ll)(nums[i] + nums[j]);
                int l = j+1, r = nums.size()-1;
                while (l < r){
                    int sum = nums[l] + nums[r];

                    if (sum == toFind){
                        st.insert({nums[i], nums[j], nums[l], nums[r]});

                        l+=1;
                        r-=1;
                    } else if (sum > toFind){
                        r-=1;
                    } else {
                        l+=1;
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};