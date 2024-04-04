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
        long long ans = 1;
        while (n>0){
            if (n%2){
                ans = (ans*x)%mod;
                n-=1;
            } else {
                x = (x*x)%mod;
                n/=2;
            }
        }

        return ans%mod;
    }
};