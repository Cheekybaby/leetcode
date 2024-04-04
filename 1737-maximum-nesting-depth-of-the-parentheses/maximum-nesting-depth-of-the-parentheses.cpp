class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxDepth = 0;
        for (int i=0; i<s.length(); i+=1){
            if (s[i] == '('){
                depth+=1;
                maxDepth = max(maxDepth, depth);
            } else if (s[i] == ')'){
                depth-=1;
            }
        }

        return maxDepth;
    }
};