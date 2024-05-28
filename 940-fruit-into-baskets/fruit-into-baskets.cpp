class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int i=0, j=0;
        int ans = 0, total = 0;
        while (j<fruits.size()){
            mpp[fruits[j]]+=1;
            total+=1;
            while (mpp.size()>2){
                mpp[fruits[i]]-=1;
                total-=1;
                if (mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                i+=1;
            }

            ans = max(ans, total);
            j+=1;
        }

        return ans;
    }
};