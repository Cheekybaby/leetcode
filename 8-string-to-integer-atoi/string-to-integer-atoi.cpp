class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        string temp;
        int i=0;
        while (s[i] == ' ') {
            i += 1;
        }
        if (s[i] == '-') {
            neg = true;
            i+=1;
        } else if (s[i] == '+'){
            i+=1;
        }

        for(i; i<s.length(); i+=1){
            if (s[i] >= '0' && s[i] <= '9'){
                temp += s[i];
            } else {
                break;
            }
        }

        cout << temp << endl;
        
        i = 0;
        while (temp[i] == '0'){
            i+=1;
        }
        temp = temp.substr(i, temp.length()-i+1);

        if (temp.length() == 0) return 0;
        if (temp.length() >= 11) {
            if (neg) return INT_MIN;
            else return INT_MAX;
        }

        long long ans = stol(temp);
        if (neg) ans = -ans;
        if (ans > INT_MAX) return INT_MAX;
        else if (ans < INT_MIN) return INT_MIN;
        return ans;
    }
};