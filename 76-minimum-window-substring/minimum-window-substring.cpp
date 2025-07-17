class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";

        unordered_map<char, int> freq;
        for (char& c : t) {
            freq[c]++;
        }

        int length_remaining = t.length();
        int min_window[2] = {0, INT_MAX};
        int i = 0;

        for (int j = 0; j < s.length(); j++) {
            char ch = s[j];
            if (freq[ch] > 0) {
                length_remaining -= 1;
            }
            freq[ch] -= 1;

            if (length_remaining == 0) {
                while (true) {
                    char c = s[i];
                    if (freq.find(c) == freq.end()) {
                        i++;
                        continue;
                    }
                    if (freq[c] == 0)
                        break;
                    freq[c]++;
                    i++;
                }

                if (j - i < min_window[1] - min_window[0]) {
                    min_window[0] = i;
                    min_window[1] = j;
                }

                freq[s[i]]++;
                length_remaining++;
                i++;
            }
        }
        return min_window[1] >= s.length()
                   ? ""
                   : s.substr(min_window[0], min_window[1] - min_window[0] + 1);
    }
};