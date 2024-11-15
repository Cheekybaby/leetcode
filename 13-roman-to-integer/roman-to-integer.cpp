class Solution {
public:
    int romanToInt(string s) {
        int n = 0;
        for(int i=0; i<s.length(); i+=1){
            cout << i << " ";
            char c = s[i];
            if (c == 'I'){
                if (i+1 < s.length() && (
                    s[i+1] == 'V' || s[i+1] == 'X'
                )) {
                    if (s[i+1] == 'V'){
                        n += 4;
                        i+=1;
                    } else if (s[i+1] == 'X'){
                        n += 9;
                        i+=1;
                    }
                } else {
                    n += 1;
                }
            } else if (c == 'X'){
                if (i+1 < s.length() && (
                    s[i+1] == 'L' || s[i+1] == 'C'
                )) {
                    if (s[i+1] == 'L'){
                        n += 40;
                        i+=1;
                    } else if (s[i+1] == 'C'){
                        n += 90;
                        i+=1;
                    }
                } else {
                    n += 10;
                }
            } else if (c == 'C'){
                if (i+1 < s.length() && (
                    s[i+1] == 'D' || s[i+1] == 'M'
                )) {
                    if (s[i+1] == 'D'){
                        n += 400;
                        i+=1;
                    } else if (s[i+1] == 'M'){
                        n += 900;
                        i+=1;
                    }
                } else {
                    n += 100;
                }
            } else if (c == 'V'){
                n += 5;
            } else if (c == 'L'){
                n += 50;
            } else if (c == 'D'){
                n += 500;
            } else if (c == 'M'){
                n += 1000;
            }

            cout << n << " ";
        }

        return n;
    }
};