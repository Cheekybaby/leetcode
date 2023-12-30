class Solution {
private:
    bool isVowel(char c){
        if (c == 'a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int i=0, j=0, count = 0;
        int ans = 0;
        while (j<s.length()){
            char c = s[j];
            if (isVowel(c)){
                count+=1;
            }
            if (j-i+1 < k){
                j+=1;
            } else if (j-i+1 == k){
                ans = max(ans, count);
                if (isVowel(s[i])){
                    count-=1;
                }
                i+=1;
                j+=1;
            }
        }

        return ans;
    }
};