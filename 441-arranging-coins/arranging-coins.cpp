class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1, right = n;
        long long m = (long long)n;
        while (left <= right){
            long long mid = left + (right - left) / 2;
            if (mid*(mid+1) == 2*m) return mid;
            else if (mid*(mid+1) > 2*m) right = mid - 1;
            else left = mid + 1;
        }

        return right;
    }
};