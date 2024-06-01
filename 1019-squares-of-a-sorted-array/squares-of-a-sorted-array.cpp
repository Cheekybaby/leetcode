class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        vector<int> ans(nums.size(), 0);
        int k = nums.size()-1;
        while (left <= right){
            int l = nums[left];
            int r = nums[right];

            if (l*l < r*r){
                ans[k] = r*r;
                k-=1;
                right-=1;
            } else {
                ans[k] = l*l;
                k-=1;
                left+=1;
            }
        }

        return ans;
    }
};