class Solution {
private:
    bool isOdd(int n){
        return (n & 1);
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        while (i <= j){
            int mid = midpoint(i,j);
            if (isOdd(mid)){
                if ((mid < nums.size()-1) && nums[mid] == nums[mid+1]){
                    j = mid - 1;
                    continue;
                }
                if (mid > 0 && nums[mid] == nums[mid-1]){
                    i = mid + 1;
                    continue;
                }
            }
            else {
                if ((mid < nums.size()-1) && nums[mid] == nums[mid+1]){
                    i = mid + 1;
                    continue;
                }
                if (mid > 0 && nums[mid] == nums[mid-1]){
                    j = mid - 1;
                    continue;
                }
            }
            return nums[mid];
        }
        return -1;
    }
};