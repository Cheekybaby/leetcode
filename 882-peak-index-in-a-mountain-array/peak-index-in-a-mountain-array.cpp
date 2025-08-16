class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0, j = arr.size()-1;
        while (i <= j){
            int mid = midpoint(i, j);

            if (mid > 0 && arr[mid] < arr[mid-1]) j = mid - 1;
            else if (mid < arr.size()-1 && arr[mid] < arr[mid+1]) i = mid + 1;
            else return mid;
        }

        return -1;
    }
};