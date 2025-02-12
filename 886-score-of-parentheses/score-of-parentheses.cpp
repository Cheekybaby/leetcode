class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<string> store;
        string temp;
        int open = 0, close = 0;
        for(int i=0; i<s.length(); i++){
            temp += s[i];
            if(s[i] == '('){
                open++;
            } else {
                close++;
            }

            if (open - close == 0){
                store.push_back(temp);
                temp = "";
            }
        }
        long long ans = 0;
        for(auto &item:store){
            string x = item;
            ans += solve(x);
        }
        return ans;
    }

private:
    int solve(string &s){
        stack<int> st;
        int score = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(score);
                score = 0;
            } else {
                score = st.top() + max(2*score, 1);
                st.pop();
            }
        }

        return score;
    }
};