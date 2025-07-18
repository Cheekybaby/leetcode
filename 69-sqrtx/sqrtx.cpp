class Solution {
private:
    int lowerBound(int x){
        int i = 1, j = x;
        while (i <= j){
            int mid = i + (j - i)/2;
            if ((long long)mid * mid == (long long)x) return mid;
            else if ((long long)mid * mid > (long long)x) j = mid-1;
            else i = mid + 1;
        }
        return j;
    }
public:
    int mySqrt(int x) {
        return lowerBound(x);
    }
};