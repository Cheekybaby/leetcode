class Solution {
public:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    int maxVowels(string s, int k) {
        int i = 0, j = 0, count = 0, maxCount = 0;

        while (j<s.length()){
            if (isVowel(s[j])){
                count++;
            }
            if (j-i+1<k){
                j++;
            } else if (j-i+1==k){
                maxCount = max(maxCount, count);
                if (isVowel(s[i])){
                    count--;
                }
                i++;
                j++;
            }
        }

        return maxCount;
    }
};