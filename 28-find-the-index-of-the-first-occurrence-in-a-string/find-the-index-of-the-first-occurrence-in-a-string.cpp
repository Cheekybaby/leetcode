class Solution {
public:
    vector<int> prefixfunc(string s){
        int n = s.length();
        vector<int> pi(n);
        for (int i=1; i<n; i+=1){
            int j = pi[i-1];
            while (j>0 && s[j]!=s[i]){
                j = pi[j-1];
            }

            if (s[i] == s[j]){
                j+=1;
            }
            pi[i] = j;
        }
        
        return pi;
    }

    int strStr(string haystack, string needle) {
        string s = needle+"#"+haystack;
        vector<int> prefix = prefixfunc(s);
        int n = needle.length();
        for(int i=n+1; i<prefix.size(); i+=1){
            if (prefix[i] == n) return (i-(2*n));
        }

        return -1;
    }
};