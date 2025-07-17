class Solution {
private:
    int getNumber(string &s){
        bool neg = false;
        
        if (s[0] == '-'){
            neg = true;
            s = s.substr(1);
        }
        
        int n = stoi(s);
        
        return (neg) ? -1*n : n;
    }
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
                int num = getNumber(it);
                cout << num << endl;
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