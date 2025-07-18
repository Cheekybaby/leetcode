class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1, j = b.length()-1;
        
        bool carry = false;

        int n = max(a.length(), b.length());
        
        string sum(n+1, '0');

        while (i >=0 || j >= 0){
            bool op1 = (i >= 0 && a[i] == '1');
            bool op2 = (j >= 0 && b[j] == '1');

            if (op1 & op2){
                if (carry){
                    sum[n] = '1';
                }
                carry = true;
            } else {
                if (op1 ^ op2){
                    if (carry){
                        carry = true;
                    } else {
                        sum[n] = '1';
                    }
                } else {
                    if (carry){
                        sum[n] = '1';
                        carry = false;
                    }
                }
            }
            i--;
            j--;
            n--;
        }
        if (carry) sum[0] = '1';
        
        return (carry) ? sum : sum.substr(1);
    }
};