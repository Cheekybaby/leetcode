class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        int len = (n - numFriends) + 1;
        if (numFriends == 1) return word;
        string ans = "";
        for (int i=0; i<n; i+=1){
            ans = max(ans, word.substr(i, len));
        }

        return ans;
    }
};