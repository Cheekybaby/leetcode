class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i += 1) {
            m[s[i]]++;
        }
        int len = 0;
        for (auto& it : m) {
            int x = it.second;
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