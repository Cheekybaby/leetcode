class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
       long long l = 1, r = num/2;
       while(l <= r){
        long long mid = midpoint(l, r);
        if (mid*mid == num){
            return true;
        } else if (mid * mid < num){
            l = mid + 1;
        } else{
            r = mid-1;
        }
       }

       return false;
    }
};