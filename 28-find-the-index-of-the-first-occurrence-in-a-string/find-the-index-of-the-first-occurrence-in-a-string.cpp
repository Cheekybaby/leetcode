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
        vector<int> prefix = prefixfunc(needle); // Space used is O(needle.length())
        int i=0, j=0;
        while (i<haystack.length() && j<needle.length()){
            if (haystack[i] == needle[j]){
                i+=1;
                j+=1;
            } else {
                if (j==0){
                    i+=1;
                } else {
                    j = prefix[j-1];
                }
            }
        }

        if (j == needle.length()) return i-j;
        return -1;
    }
};