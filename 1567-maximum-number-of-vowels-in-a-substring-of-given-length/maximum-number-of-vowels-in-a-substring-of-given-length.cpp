class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};
        int i = 0, j = 0;
        int ans = 0, count = 0;
        while (j < s.length()) {
            char c = s[j];
            if (j - i + 1 < k) {
                if (v.count(c)) {
                    count += 1;
                }
            } else if (j-i+1 == k){
                if (v.count(c)){
                    count+=1;
                }
                ans = max(ans, count);

                if (v.count(s[i])){
                    count-=1;
                }

                i+=1;
            }
            j+=1;
        }

        return ans;
    }
};