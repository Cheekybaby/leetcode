class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        auto gcd = [](int len1, int len2) {
            while(len2){
                int temp = len1 % len2;
                len1 = len2;
                len2 = temp;
            }
            return len1;
        };
        int gcd_len = gcd(str1.length(), str2.length());
        return str1.substr(0, gcd_len);
    }
};