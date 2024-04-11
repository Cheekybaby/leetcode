class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (char ch:num){
            while (!st.empty() && k>0  && st.top()>ch){
                st.pop();
                k-=1;
            }
            st.push(ch);
        }

        while (k>0 && !st.empty()){
            st.pop();
            k-=1;
        }

        string ans;
        while (!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while (ans[i] == '0'){
            i+=1;
        }

        ans = ans.substr(i, ans.size()-i);
        if (ans.empty()){
            return "0";
        }

        return ans;
    }
};