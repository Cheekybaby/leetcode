class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n-1] += (1);
        int carry = digits[n-1]/10;
        digits[n-1] %= 10;

        if (carry == 0) return digits;

        for(int i=n-2; i>=0; i--){
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] %= 10;

            if (carry == 0) break;
        }
        

        if (carry){
            vector<int> new_digits(n+1, 0);
            new_digits[0] = 1;
            for(int i=1; i<n+1; i++){
                new_digits[i] = digits[i-1];
            }
            return new_digits;
        }
        return digits;
    }
};