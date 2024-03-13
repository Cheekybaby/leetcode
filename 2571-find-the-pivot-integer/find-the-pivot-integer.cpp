class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        // Binary Search
        int l=1, r=n;
        while (l<=r){
            int mid = l+(r-l)/2;
            int suml = mid*(mid+1)/2;
            int sumr = sum - suml + mid;
            if (suml == sumr){
                return mid;
            } else if (suml < sumr){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return -1;
    }
};