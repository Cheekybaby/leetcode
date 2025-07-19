class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int min_element = nums[l];
        while(l <= r){
            if (nums[l] <= nums[r]){
                min_element = min(min_element, nums[l]);
                break;
            }
            int mid = l + (r - l)/2;
            min_element = min(min_element, nums[mid]);

            if (nums[mid] < nums[l]) r = mid-1;
            else l = mid+1;
        }
        return min_element;
    }
};