class Solution {
public:
    bool isPrefixSuffix(string &s, string &t){
        int n = s.length(), m = t.length();
        if(n > m) return false;
        // Check for prefix
        for(int i=0; i<n; i+=1){
            if (s[i] != t[i]) return false;
        }
        // Check suffix
        string temp;
        for(int i=m-n; i<m; i+=1){
            temp+=t[i];
        }
        if (temp != s) return false;
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for(int i=0; i<words.size(); i+=1){
            for(int j=i+1; j<words.size(); j+=1){
                if(isPrefixSuffix(words[i], words[j])) cnt += 1;
            }
        }

        return cnt;
    }
};