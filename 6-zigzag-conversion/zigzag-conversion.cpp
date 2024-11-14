class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<int> rows(s.length(), 0);
        int k = 1;
        bool flip = false;
        for(int i=0; i<s.length(); i+=1){
            // Check if the series should be incrementing or decrementing
            if (k == numRows){
                flip = true;
            } else if (k == 1){
                flip = false;
            }

            // Update rows
            rows[i] = k;
            
            // Update the value of k
            if (!flip){
                k+=1;
            } else {
                k-=1;
            }

        }
        for(auto &it:rows){
            cout << it << " ";
        }
        string output;
        int c=1;
        while (numRows--){
            for(int i=0; i<rows.size(); i+=1){
                if (rows[i] == c){
                    output += s[i];
                }
            }
            c+=1;
        }

        return output;
    }
};