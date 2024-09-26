class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);

        int maxLength = 1, lastChain = 0;

        for (int i=1; i<pairs.size(); i+=1){
            if (pairs[i][0] > pairs[lastChain][1]){
                maxLength+=1;
                lastChain = i;
            }
        }
        
        return maxLength;
        
    }
};

// nlogn + n -> O(nlogn)