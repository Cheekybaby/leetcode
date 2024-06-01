class Solution {
public:
    int lowerbound(vector<int> &nums, int x){
        int left = 0, right = nums.size()-1;
        int ans = -1;
        while (left<=right){
            int mid = left + (right - left) /2;
            if (nums[mid] == x){
                ans = mid;
                right = mid - 1;
            } else if (nums[mid] > x) right = mid - 1;
            else left = mid + 1; 
        }

        return ans;
    }
    int upperbound(vector<int> &nums, int x){
        int left = 0, right = nums.size()-1;
        int ans = -1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == x){
                ans = mid;
                left = mid + 1;
            } else if (nums[mid] > x) right = mid - 1;
            else left = mid + 1;
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lowerbound(nums, target);
        int r = upperbound(nums, target);
        return {l, r};
    }
};