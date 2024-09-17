class Solution {
public:
    double power(double x, long long n){
        if (n == 0) return 1;
        
        if (n < 0) return 1.0 / power(x, -n);
        if (n%2){
            double res = power(x, n/2);
            return res * res * x;
        } else {
            double res = power(x, n/2);
            return res * res;
        }
    }
    double myPow(double x, int n) {
        return power(x, (long long)n);
    }
};