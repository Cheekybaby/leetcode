class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int> a = {0};
        for(int i=0; i<derived.size(); i+=1){
            a.push_back(a[i] ^ derived[i]);
        }

        bool checkForZero = (a[0] == a[a.size()-1]);

        vector<int> b = {1};
        for(int i=0; i<derived.size(); i+=1){
            b.push_back(b[i] ^ derived[i]);
        }

        bool checkForOne = (b[0] == b[b.size()-1]);

        return checkForZero | checkForOne;
    }
};