class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int j = 0;
        int maxlen = 0;
        for(int i=0; i<s.length(); i++){
            char x = s[i];
            if (st.count(x)){
                int len = i - j;
                maxlen = max(len, maxlen);
                while(j < i && st.count(x)){
                    st.erase(s[j]);
                    j++;
                }
            }
            st.insert(x);
        }
        maxlen = max(maxlen, int(st.size()));
        return maxlen;
    }
};