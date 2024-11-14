class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        bool neg = false;
        if (x < 0){
            neg = true;
            x = abs(x);
        }
        while(x>0){
            int rem = x%10;
            rev = rev*10 + rem;

            x/=10;
        }
        if (neg) rev = -rev;
        if (rev > INT_MAX || rev < INT_MIN){
            return 0;
        }
        return rev;
    }
};