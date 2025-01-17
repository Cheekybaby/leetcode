class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xo = 0;
        for(int i=0; i<derived.size(); i++){
            xo ^= derived[i];
        }

        return !xo;
    }
};