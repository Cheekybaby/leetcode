class Solution {
public:
    int minimumLength(string s) {
        vector<int> m(26);
        for (int i = 0; i < s.length(); i += 1) {
            m[s[i]-'a']++;
        }
        int len = 0;
        for (auto& it : m) {
            int x = it;
            if (x > 2) {
                if (x % 2 == 1) {
                    len += 1;
                } else {
                    len += 2;
                }
            } else {
                len += x;
            }
        }

        return len;
    }
};