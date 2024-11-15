class Solution {
public:
    int romanToInt(string s) {
        int n = 0;
        map<char, int> symbol = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i=0; i<s.length(); i+=1){
            if (i+1 < s.length() && symbol[s[i]] < symbol[s[i+1]]){
                n += symbol[s[i+1]] - symbol[s[i]];
                i+=1;
            } else {
                n += symbol[s[i]];
            }
        }

        return n;
    }
};