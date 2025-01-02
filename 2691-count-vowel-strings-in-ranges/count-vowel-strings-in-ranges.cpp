class Solution {
public:
    bool check(string &s){
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int i = 0, j = s.length()-1;
        if (st.find(s[i]) != st.end() && st.find(s[j]) != st.end()){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n+1, 0);
        for(int i=0; i<n; i+=1){
            if (check(words[i])){
                pref[i+1] = pref[i] + 1;
            } else {
                pref[i+1] = pref[i];
            }
        }
        vector<int> ans;
        for(int i=0; i<queries.size(); i+=1){
            int left = queries[i][0];
            int right = queries[i][1];

            int x = pref[right+1] - pref[left];
            ans.push_back(x);            
        }

        return ans;
    }
};