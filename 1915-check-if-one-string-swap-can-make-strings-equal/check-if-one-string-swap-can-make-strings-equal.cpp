class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        if (n == 1) return (s1 == s2);
        vector<int> a(26), b(26);
        int cnt = 0;
        for(int i=0; i<s1.length(); i++){
            if (s1[i] != s2[i]) cnt += 1;
            a[s1[i] - 'a']++;
            b[s2[i] - 'a']++;
        }

        return (cnt <= 2 && a == b);
    }
};