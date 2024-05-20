class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0, a=0, l=0, o=0, n=0;
        for (int i=0; i<text.length(); i+=1){
            if (text[i] == 'b') b+=1;
            else if (text[i] == 'a') a+=1;
            else if (text[i] == 'l') l+=1;
            else if (text[i] == 'o') o+=1;
            else if (text[i] == 'n') n+=1;
        }
        o/=2;
        l/=2;

        int count = min(min(b, a), min(l,o));
        count = min(count, n);

        return count;
    }
};