class Solution {
public:
    int punishmentNumber(int n) {
        vector<int> v;
        for(int i=1; i<=n; i+=1){
            string num = to_string(i*i);
            if(check(num, i)){
                v.push_back(i*i);
            }
        }
        int ans = 0;
        for(int i=0; i<v.size(); i++){
            ans += v[i];
        }

        return ans;
    }
private:
    bool check(string &s, int n) {
        if (s == "" && n == 0) return true;

        if (n < 0) return false;

        for(int i=0; i<s.length(); i++){
            string left = s.substr(0, i+1);
            string right = s.substr(i+1);

            int l = stoi(left);

            if(check(right, n - l)) return true;
        }

        return false;
    }
};