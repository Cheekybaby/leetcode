class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int size = operations.size(), i = 0;
        while (size--){
            string op = operations[i];
            if (op == "C"){
                st.pop();
            } else if (op == "D"){
                int num = st.top();
                st.push(2*num);
            } else if (op == "+"){
                int arr[2];
                for (int i=0; i<2; i+=1){
                    arr[i] = st.top();
                    st.pop();
                }
                int num = arr[0]+arr[1];
                st.push(arr[1]);
                st.push(arr[0]);
                st.push(num);
            } else {
                int num = stoi(op);
                st.push(num);
            }
            i+=1;
        }


        // Sum of all the scores
        int sum = 0;
        while (st.size()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};