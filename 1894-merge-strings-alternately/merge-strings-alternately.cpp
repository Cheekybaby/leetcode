class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0, j=0;
        string ans;
        while (i<word1.length() && j<word2.length()){
            if (i<=j){
                ans+=word1[i]; 
                i+=1;
            }else {
                ans+=word2[j]; 
                j+=1;
            }
        }

        while (i<word1.length()){
            ans+=word1[i];
            i+=1;
        }
        while (j<word2.length()){
            ans+=word2[j];
            j+=1;
        }

        return ans;
    }
};