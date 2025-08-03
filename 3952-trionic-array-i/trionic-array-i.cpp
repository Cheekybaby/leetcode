class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        bool inc = true;
        int cnt = 0;
        for(int i=1; i<n-1; i++){
            if (nums[i] == nums[i-1]) return false;
            if (inc){
                if (nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                    cnt += 1;
                    inc = false;
                } else if (nums[i] < nums[i-1] && nums[i] < nums[i+1]) return false;
            } else {
                if (nums[i] < nums[i-1] && nums[i] < nums[i+1]) {
                    cnt += 1;
                    inc = true;
                } else if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) return false;
            }
        }
        if (cnt == 2) return true;
        return false;
    }
};