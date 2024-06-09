class Solution {
public:
    double power(double x, long long n){
        if (n == 0) return 1.0;

        if (n<0) return 1.0/power(x, -n);

        if (n%2){
            double result = power(x, n/2);
            return result*result*x;
        } else {
            double result = power(x, n/2);
            return result*result;
        }
    }
    double myPow(double x, int n) {
        return power(x, (long long)n);
    }
};