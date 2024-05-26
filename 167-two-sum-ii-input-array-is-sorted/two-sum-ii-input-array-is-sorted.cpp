class Solution {
public:
    int binarySearch(vector<int> &v, int left, int right, int x){
        while (left<=right){
            int mid = left + (right-left)/2;
            if (v[mid] == x) return mid;
            else if (v[mid]>x) right = mid-1;
            else left = mid+1;
        }

        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i=0; i<numbers.size(); i+=1){
            int tofind = target - numbers[i];
            if (binarySearch(numbers, i+1, numbers.size()-1, tofind) != -1){
                return {i+1, binarySearch(numbers, i+1, numbers.size()-1, tofind)+1};
            }
        }
        return {-1,-1};
    }
};