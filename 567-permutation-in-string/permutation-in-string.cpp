class Solution {
private:
    bool isEqual(int a[26], int b[26]){
        for(int i=0; i<26; i++){
            if (a[i] != b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int freq1[26] = {0};
        int freq2[26] = {0};

        for(auto ch:s1){
            freq1[ch-'a']++;
        }
        for(int i=0; i<s1.length(); i++){
            freq2[s2[i]-'a']++;
        }

        if (isEqual(freq1, freq2)) return true;
        int j = 0;
        for(int i=s1.length(); i<s2.length(); i++){
            freq2[s2[i]-'a']++;
            freq2[s2[j]-'a']--;

            if (isEqual(freq1, freq2)) return true;
            j++;
        }
        return false;
    }
};