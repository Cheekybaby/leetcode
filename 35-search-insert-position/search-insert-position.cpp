class Solution {
private:
    int lowerBound(vector<int> &v, int target){
        int i = 0, j = v.size()-1;
        while(i <= j){
            int mid = i + (j - i)/2;
            if (v[mid] == target) return mid;
            else if (v[mid] > target) j = mid-1;
            else i = mid + 1;
        }

        return i;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return lowerBound(nums, target);
    }
};