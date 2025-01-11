class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        vector<int> above = {1,1};
        for(int i=2; i<=rowIndex; i+=1){
            vector<int> curr;
            for(int j=0; j<=i; j+=1){
                if (j == 0 || j == i){
                    curr.push_back(1);
                    continue;
                }
                int n = above[j-1] + above[j];
                curr.push_back(n);
            }

            above = curr;
        }

        return above;
    }
};