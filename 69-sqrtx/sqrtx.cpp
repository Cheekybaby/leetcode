class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x;
        int ans = x;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if ((long long)mid*mid == (long long)x){
                return mid;
            } else if ((long long)mid*mid < (long long)x){
                left = mid + 1;
            } else right = mid - 1;
        }

        return right;
    }
};