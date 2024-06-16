class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int i = 0;
        while (i<operations.size()){
            string c = operations[i];

            if (c == "+"){
                if (st.size()>1){
                    int a, b;
                    a = st.top();
                    st.pop();
                    b = st.top();
                    st.push(a);
                    st.push(a+b);
                }
            } else if (c == "D"){
                if (!st.empty()){
                    st.push(2*(st.top()));
                }
            } else if (c == "C"){
                if (!st.empty()) st.pop();
            } else {
                int x = stoi(c);
                st.push(x);
            }
            i+=1;
        }
        int ans = 0;
        while (!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};