class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isDividendNeg = false, isDivisorNeg = false;
        long long divid = dividend, divis = divisor;

        if (divis == 1){
            return divid;
        } else if (divis == -1){
            if (divid > 0) {
                return -divid;
            } else {
                if (-divid > INT_MAX) return INT_MAX;
                else return -divid;
            }
        }
        
        if (dividend < 0) {
            isDividendNeg = true;
            divid *= -1;
        }

        if (divisor < 0) {
            isDivisorNeg = true;
            divis *= -1;
        }

        long long quotient = 0;
        long long d = divis;
        while (d <= divid) {
            quotient += 1;
            d += divis;
        }

        if ((isDividendNeg == true && isDivisorNeg == false) ||
            (isDividendNeg == false && isDivisorNeg == true)) {
            quotient *= -1;
        }

        if (quotient > INT_MAX)
            return INT_MAX;
        else if (quotient < INT_MIN)
            return INT_MIN;

        return quotient;
    }
};