class Solution {
long mod = 1e9+7;
public:
    int countGoodNumbers(long long n) {
        long long even = (n/2)+n%2;
        long long odd = (n/2);

        return (power(5, even)*power(4, odd))%mod;
    }
private: // Binary Exponentiation
    long long power(long long x, long long n){
        if (n == 0) return 1;

        long long temp = power(x, n/2);

        if (n%2){
            return (temp*temp*x)%mod;
        } else {
            return (temp*temp)%mod;
        }
    }
};