class Solution {
public:
    int maximumfreq(vector<int> &v){
        int maxi = INT_MIN;
        for (int i=0; i<26; i+=1){
            maxi = max(maxi, v[i]);
        }

        return maxi;
    }
    int characterReplacement(string s, int k) {
        int i=0, j=0;
        vector<int> v(26,0);
        int ans = 0;
        while (j<s.length()){
            v[s[j]-'A']+=1;
            int maxfreq = maximumfreq(v);
            int winlen = j-i+1;
            if (winlen - maxfreq <= k){
                ans = max(ans, winlen);
            } else {
                while (winlen-maxfreq > k){
                    v[s[i]-'A']-=1;
                    i+=1;
                    maxfreq = maximumfreq(v);
                    winlen = j-i+1;
                }

                if (winlen-maxfreq <= k){
                    ans = max(ans, winlen);
                }
            }
            j+=1;
        }

        return ans;
    }
};