class Solution {
public:
    bool check(string &pref, string &word){
        int n = pref.length(), m = word.length();
        if (n > m) return false;

        if (word.substr(0, n) == pref){
            return true;
        }
        return false;
    }
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(int i=0; i<words.size(); i+=1){
            if (check(pref, words[i])) cnt +=1 ;
        }

        return cnt;
    }
};