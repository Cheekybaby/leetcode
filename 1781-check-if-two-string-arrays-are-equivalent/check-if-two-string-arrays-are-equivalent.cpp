class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s;
        for(int i=0; i<word1.size(); i+=1){
            s+=word1[i];
        }
        string t;
        for (int i=0; i<word2.size(); i+=1){
            t+=word2[i];
        }

        return (s==t);
    }
};