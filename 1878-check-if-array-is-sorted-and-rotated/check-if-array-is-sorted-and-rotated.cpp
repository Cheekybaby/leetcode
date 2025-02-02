class Solution {
public:
    bool check(vector<int>& nums) {
        int inversions = 0;
        int n = nums.size();
        if (n <= 1) return true;
        for(int i=1; i<n; i++){
            if (nums[i] < nums[i-1]){
                inversions++;
            }
        }

        if (nums[n-1] > nums[0]) inversions++;

        return inversions <= 1;
    }
};