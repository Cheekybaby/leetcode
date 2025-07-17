class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string &it:ops){
            if (it == "+"){
                int a = st.top();
                st.pop();
                int sum = a + st.top();
                st.push(a);
                st.push(sum);
            } else if (it == "D"){
                int a = st.top() * 2;
                st.push(a);
            } else if (it == "C"){
                st.pop();
            } else {
                int num = stoi(it);
                st.push(num);
            }
        }
        int total_score = 0;
        while(!st.empty()){
            total_score += st.top();
            st.pop();
        }

        return total_score;
    }
};