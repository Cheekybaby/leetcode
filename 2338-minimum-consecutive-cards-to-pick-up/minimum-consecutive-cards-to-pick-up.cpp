class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mpp;
        int i=0, j=0;
        int ans = INT_MAX;
        while (j<cards.size()){
            auto num = mpp.find(cards[j]);
            if (num == mpp.end()){
                mpp.insert({cards[j], j});
            } else {
                while (cards[i]!=cards[j]){
                    mpp.erase(cards[i]);
                    i++;
                }
                ans = min(ans, j-i+1);
                num->second = j;
                i++;
            }
            j++;
        }
        if (ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};