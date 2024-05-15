class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i+=1){
            if (i!=0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = nums.size()-1;

            while (j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j+=1;
                    k-=1;

                    while(j<k && nums[j] == nums[j-1]) j+=1;
                    while(j<k && nums[k] == nums[k+1]) k-=1;
                } else if (sum>0){
                    k-=1;
                } else {
                    j+=1;
                }
            }
        }

        return ans;
    }
};