class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        long long i = 1, j = num/2;
        while (i <= j){
            long long mid = midpoint(i, j);
            long long prod = mid * mid;
            if (prod == num) return true;
            else if (prod > num) j = mid - 1;
            else i = mid + 1;
        }

        return false;
    }
};