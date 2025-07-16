class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        string merged;
        while (i < word1.length() || i < word2.length()){
            bool x = (i < word1.length()) ? true : false;
            bool y = (i < word2.length()) ? true : false;

            if (x) merged += word1[i];
            if (y) merged += word2[i];
            i+=1;
        }

        return merged;
    }
};