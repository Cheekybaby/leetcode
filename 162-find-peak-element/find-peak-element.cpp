class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        while(i <= j){
            int mid = midpoint(i,j);

            if (mid > 0 && nums[mid] < nums[mid-1]) j = mid - 1;
            else if (mid < nums.size()-1 && nums[mid] < nums[mid+1]) i = mid + 1;
            else return mid;
        }

        return -1;
    }
};