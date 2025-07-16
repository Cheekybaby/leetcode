class Solution {
private:
    int maxFrequency(vector<int> &freq){
        int maxi = 0;
        for(auto &f:freq){
            maxi = max(maxi, f);
        }
        return maxi;
    }
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int i=0, j=0;
        int maxlen = 0;
        while(j < s.length()){
            freq[s[j] - 'A']+=1;
            int max_freq = maxFrequency(freq);
            int winlen = j - i + 1;
            if (winlen - max_freq <= k){
                maxlen = max(maxlen, winlen);
            } else {
                while(winlen - max_freq > k){
                    freq[s[i]-'A']-=1;
                    i+=1;
                    winlen = j - i + 1;
                    max_freq = maxFrequency(freq);
                }

                if (winlen - max_freq <= k){
                    maxlen = max(maxlen, winlen);
                }
            }
            j+=1;
        }
        return maxlen;
    }
};