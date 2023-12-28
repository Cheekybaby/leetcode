using ll = long long;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0; i<n-3; i+=1){
            for (int j=i+1; j<n-2; j+=1){
                ll newtarget = ll(target) - ll(nums[i]) - ll(nums[j]);
                int low = j+1, high = n-1;
                while (low<high){
                    if (nums[low]+nums[high]<newtarget){
                        low+=1;
                    } else if (nums[low]+nums[high]>newtarget){
                        high-=1;
                    } else {
                        st.insert({nums[i], nums[j], nums[low], nums[high]});
                        low+=1;
                        high-=1;
                    }
                }
            }
        }
        for (auto it:st){
            ans.push_back(it);
        }

        return ans;
    }
};