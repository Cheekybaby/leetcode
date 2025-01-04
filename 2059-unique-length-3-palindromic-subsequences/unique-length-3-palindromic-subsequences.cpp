class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for(char c:s){
            letters.insert(c);
        }
        int ans = 0;
        for(char letter:letters){
            int i = -1;
            int j = 0;

            for(int k=0; k<s.length(); k+=1){
                if (s[k] == letter){
                    if (i == -1){
                        i = k;
                    }
                    j = k;
                }
            }

            unordered_set<char> between;
            for(int k=i+1; k<j; k+=1){
                between.insert(s[k]);
            }

            ans+=between.size();
        }

        return ans;
    }
};