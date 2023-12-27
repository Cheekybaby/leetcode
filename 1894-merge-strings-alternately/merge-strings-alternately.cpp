class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        string ans;
        int i=0;
        while (i<l1 && i<l2){
            ans+=word1[i];
            ans+=word2[i];
            i+=1;
        }
        while (i<l1){
            ans+=word1[i];
            i+=1;
        }
        while (i<l2){
            ans+=word2[i];
            i+=1;
        }

        return ans;
    }
};