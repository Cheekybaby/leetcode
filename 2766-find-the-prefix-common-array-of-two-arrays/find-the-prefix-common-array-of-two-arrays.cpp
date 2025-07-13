class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);

        unordered_set<int> as, bs;
        for(int i=0; i<n; i++){
            int cnt = 0;
            if (A[i] == B[i]) cnt += 1;
            else {
                if (as.count(B[i])) cnt += 1;
                if (bs.count(A[i])) cnt += 1;
            }
            if (i > 0) cnt += ans[i-1];
            
            ans[i] = cnt;

            as.insert(A[i]);
            bs.insert(B[i]);
        }
        return ans;
    }
};