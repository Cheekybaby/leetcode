class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = -1, vote1 = 0;
        int cand2 = -1, vote2 = 0;

        for (int i=0; i<nums.size(); i+=1){
            if (nums[i] == cand1){
                vote1 += 1;
            } else if (nums[i] == cand2){
                vote2 += 1;
            } else if (vote1 == 0){
                cand1 = nums[i];
                vote1 += 1;
            } else if (vote2 == 0){
                cand2 = nums[i];
                vote2 += 1;
            } else {
                vote1 -= 1;
                vote2 -= 1;
            }
        }

        vote1 = 0, vote2 = 0;

        for (auto it:nums){
            if (it == cand1){
                vote1 += 1;
            } else if (it == cand2){
                vote2 += 1;
            }
        }
        vector<int> ans;
        if (vote1 > nums.size()/3){
            ans.push_back(cand1);
        }
        if (vote2 > nums.size()/3){
            ans.push_back(cand2);
        }

        return ans;
    }
};