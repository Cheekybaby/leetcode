class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> st;
        vector<int> ans(n);

        ans[0] = (A[0] == B[0]) ? 1 : 0;
        ans[n-1] = n;
        st.insert(A[0]);
        st.insert(B[0]);
        
        for (int i=1; i<n-1; i+=1){
            int x = A[i];
            int y = B[i];

            int cnt = 0;
            if (x == y) {
                cnt += 1;
            }

            if (st.count(x) == 1) cnt += 1;
            if (st.count(y) == 1) cnt += 1;
            st.insert(x);
            st.insert(y);

            ans[i] = ans[i-1] + cnt;
        }

        return ans;
    }
};