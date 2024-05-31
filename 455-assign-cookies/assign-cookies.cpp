class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0, j=0;
        while (i<g.size()){
            while (j<s.size() && s[j]<g[i]){
                j+=1;
            }

            if (j == s.size()){
                break;
            }
            i+=1;
            j+=1;
        }

        return i;
    }
};